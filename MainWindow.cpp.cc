
#include "MainWindow.h"

using namespace std;
using namespace interval_arithmetic;
const QString MainWindow::NORX = "0.0 1.0";
const QString MainWindow::NORF = "1.0 0.0";
const QString MainWindow::NORVALXX = "0.5";
const QString MainWindow::INX = "-0.1,0.1 0.99,1.01";
const QString MainWindow::INF = "-0.1,0.1 0.99,1.01";
const QString MainWindow::INVALXX = "0.45,0.55";

MainWindow::MainWindow() {
    widget.setupUi(this);
    widget.valueBtn->setChecked(true);
    on_valueBtn_clicked();
    widget.normalBtn->setChecked(true);
    on_normalBtn_clicked();

    connect(widget.computeBtn, SIGNAL(clicked()), this, SLOT(computeResult()));
    normals.filled = false;
    intervals.filled = false;
}

MainWindow::~MainWindow() {
}

void MainWindow::computeResult() {
    switch (arit) {
        case Arithmetic::NORMAL:
            switch (target) {
                case Target::VALUE:
                    computeNormalValue();
                    break;
                case Target::COEFF:
                    computeNormalCoeffns();
                    break;
            }
            break;
        case Arithmetic::INTERVAL:
            switch (target) {
                case Target::VALUE:
                    computeIntervalValue();
                    break;
                case Target::COEFF:
                    computeIntervalCoeffns();
                    break;
            }
    }

}

void MainWindow::computeNormalValue() {
    normalParse();
    parseNormalPointIn();
    if (normals.st == -1) {
        printHardwareProblem();
        return;
    } else if (normals.st == -2) {
        printWrongInput();
        return;
    }
    long double res = NormalArithmetics::naturalSplineValue(normals.n, normals.x, normals.f, normals.xx, normals.st);
    if (normals.st == -1) {
        printHardwareProblem();
        return;
    }
    out << setprecision(14) << scientific << res << "st=" << normals.st;
    widget.output->clear();
    widget.output->setPlainText(QString::fromUtf8(out.str().c_str()));
}

void MainWindow::computeNormalCoeffns() {
    bool ableToCompute = true;
    normalParse();
    for (int i = 0; i < 4 && ableToCompute; ++i) {
        normals.a[i] = new (nothrow) long double[normals.n + 1];
        if (normals.a[i] == NULL)
            ableToCompute = false;
    }
    if (!ableToCompute) {
        printHardwareProblem();
        return;
    } else if (normals.st == -2) {
        printWrongInput();
        return;
    }
    NormalArithmetics::naturalSplineConeffns(normals.n, normals.x, normals.f, normals.a, normals.st);
    if (normals.st == -1) {
        printHardwareProblem();
        return;
    }
    out << setprecision(14) << scientific;
    for (int j = 0; j < normals.n; ++j)
        for (int i = 0; i < 4; ++i) {
            out << "a[" << i << "," << (j) << "]=" << normals.a[i][j] << ",\n";
        }
    out << "st=" << (normals.st);
    widget.output->clear();
    widget.output->setPlainText(QString::fromStdString(out.str()));
    for (int i = 0; i < 4; ++i) {
        delete[] normals.a[i];
    }
}

void MainWindow::computeIntervalValue() {
    intervalParse();
    parseIntervalPointIn();
    if (intervals.st == -1) {
        printHardwareProblem();
        return;
    } else if (intervals.st == -2) {
        printWrongInput();
        return;
    }
    Interval<long double> res;
    try {
        res = IntervalArithmetic::naturalSplineValue(intervals.n, intervals.x, intervals.f, intervals.xx, intervals.st);
    } catch (...) {
        printWrongArgument();
        return;
    }
    if (intervals.st == -1) {
        printHardwareProblem();
        return;
    }
    out << setprecision(14) << scientific;
    out << "[" << res.a << " , " << res.b << "] w=" << res.GetWidth() << endl << "st=" << intervals.st;
    widget.output->clear();
    widget.output->setPlainText(QString::fromStdString(out.str().c_str()));
    out.str("");
}
//

void MainWindow::computeIntervalCoeffns() {
    bool ableToCompute = true;
    intervalParse();
    for (int i = 0; i < 4 && ableToCompute; ++i) {
        intervals.a[i] = new (nothrow) Interval<long double>[intervals.n + 1];
        if (intervals.a[i] == NULL)
            ableToCompute = false;
    }
    if (!ableToCompute) {
        printHardwareProblem();
        return;
    } else if (intervals.st == -2) {
        printWrongInput();
        return;
    }
    try {
        IntervalArithmetic::naturalSplineConeffns(intervals.n, intervals.x, intervals.f, intervals.a, intervals.st);
    } catch (...) {
        printWrongArgument();

        return;
    }
    if (intervals.st == -1) {
        printHardwareProblem();
        return;
    }

    out << setprecision(14) << scientific;
    for (int j = 0; j <= intervals.n; ++j)
        for (int i = 0; i < 4; ++i) {
            out << "a[" << i << "," << j << "]=" << "[" << intervals.a[i][j].a << " , " << intervals.a[i][j].b << "] w=" << intervals.a[i][j].GetWidth() << endl;
        }
    out << "st=" << intervals.st;
    widget.output->clear();
    widget.output->setPlainText(out.str().c_str());
    out.str("");
    for (int i = 0; i < 4 && ableToCompute; ++i) {
        delete[] intervals.a[i];
    }
}

void MainWindow::on_coeffBtn_clicked() {
    target = Target::COEFF;
}

void MainWindow::on_intervalBtn_clicked() {
    arit = Arithmetic::INTERVAL;
    widget.ex_f->setText(INF);
    widget.ex_x->setText(INX);
    widget.ex_res_in->setText(INVALXX);
}

void MainWindow::on_normalBtn_clicked() {
    arit = Arithmetic::NORMAL;
    widget.ex_f->setText(NORF);
    widget.ex_x->setText(NORX);
    widget.ex_res_in->setText(NORVALXX);
}

void MainWindow::on_valueBtn_clicked() {
    target = Target::VALUE;
}

Components MainWindow::normalParse() {
    if (normals.filled) {
        delete[] normals.f;
        delete[] normals.x;
        delete[] normals.a;
    }
    QStringList xList = widget.xIn->text().trimmed().split(" ");
    QStringList fList = widget.fIn->text().trimmed().split(" ");
    if (xList.size() != fList.size()) {
        normals.st = -2;
        return normals;
    }
    normals.n = xList.size() - 1;
    normals.x = new (nothrow) long double[normals.n + 1];
    normals.f = new (nothrow) long double[normals.n + 1];
    normals.a = new (nothrow) long double*[4];
    normals.st = 0;
    if (normals.x == NULL || normals.f == NULL) {
        normals.st = -1;
        return normals;
    }
    for (int i = 0; i < xList.size(); ++i) {
        if (!is_number(xList[i]) || !is_number(fList[i])) {
            normals.st = -2;
            return normals;
        }
        normals.x[i] = Interval<long double>::IntRead(xList[i].toStdString()).a;
        normals.f[i] = Interval<long double>::IntRead(fList[i].toStdString()).a;

    }
    normals.xx = Interval<long double>::IntRead(widget.pointIn->text().trimmed().toStdString()).a;
    return normals;
}

IntervalComponents MainWindow::intervalParse() {
    if (intervals.filled) {
        delete[] intervals.f;
        delete[] intervals.x;
        delete[] intervals.a;
        intervals.filled = false;
    }
    intervals.filled = true;
    QStringList xList = widget.xIn->text().trimmed().split(" ");
    QStringList fList = widget.fIn->text().trimmed().split(" ");

    intervals.n = xList.size() - 1;
    intervals.x = new (nothrow) Interval<long double>[intervals.n + 1];
    intervals.f = new (nothrow) Interval<long double>[intervals.n + 1];
    intervals.a = new (nothrow) Interval<long double>*[4];
    intervals.st = 0;
    if (intervals.x == NULL || intervals.f == NULL) {
        intervals.st = -1;
        return intervals;
    }
    for (int i = 0; i < xList.size(); ++i) {
        QStringList xInterval = xList[i].trimmed().split(",");
        QStringList fInterval = xList[i].trimmed().split(",");
        if (xInterval.size() != 2 || fInterval.size() != 2 || xInterval.size() == 0) {
            intervals.st = -2;
            return intervals;
        }

        if (!is_number(xInterval[0]) || !is_number(xInterval[1]) || !is_number(fInterval[0]) || !is_number(fInterval[1])) {
            intervals.st = -2;

            return intervals;
        }
        intervals.x[i].a = Interval<long double>::LeftRead(xInterval[0].toStdString());
        intervals.x[i].b = Interval<long double>::RightRead(xInterval[1].toStdString());
        intervals.f[i].a = Interval<long double>::LeftRead(fInterval[0].toStdString());
        intervals.f[i].b = Interval<long double>::RightRead(fInterval[1].toStdString());
    }
    return intervals;
}

void MainWindow::parseIntervalPointIn() {
    QStringList pList = widget.pointIn->text().trimmed().split(",");
    if (pList.size() != 2) {
        intervals.st = -2;
        return;
    }
    if (!is_number(pList[0]) || !is_number(pList[1])) {
        intervals.st = -2;
        return;
    }
    intervals.xx.a = Interval<long double>::LeftRead(pList[0].toStdString());
    intervals.xx.b = Interval<long double>::RightRead(pList[1].toStdString());
}

void MainWindow::parseNormalPointIn() {
    QString p = widget.pointIn->text().trimmed();
    if (!is_number(p)) {
        intervals.st = -2;
        return;
    }
    normals.xx = Interval<long double>::IntRead(p.toStdString()).a;
}

bool MainWindow::is_number(QString str) {
    regex float_pattern("-?\\d{1,}\\.?\\d{0,}e?-?\\d{0,}([eE][-+]?[0-9]+)?");
    string s = str.toStdString();
    return regex_match(s, float_pattern);
}

void MainWindow::printHardwareProblem() {
    widget.output->setPlainText("Cannot compute! Hardware problem occurred.");
}

void MainWindow::printWrongInput() {
    widget.output->setPlainText("Cannot compute! Wrong input. Check the fields and try again!");
}

void MainWindow::printWrongArgument() {
    widget.output->setPlainText("Result unreachable for given arguments.");
}