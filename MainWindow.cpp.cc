
#include "MainWindow.h"
#include "NormalArithmetics.h"
#include "IntervalArithmetic.h"
#include <cstdlib>
#include <regex>
#include <sstream>
#include <qt5/QtCore/qstring.h>
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
    Components c = normalParse();
    if (c.st == -1) {
        printHardwareProblem();
        return;
    } else if (c.st == -2) {
        printWrongInput();
        return;
    }
    long double res = NormalArithmetics::naturalSplineValue(c.n, c.x, c.f, c.xx, c.st);
    if (c.st == -1) {
        printHardwareProblem();
        return;
    }
    ostringstream out;
    out << setprecision(14) << scientific << res;
    string str = out.str();
    widget.output->setPlainText(QString::fromUtf8(str.c_str()));
    QTextCursor cursor = widget.output->textCursor();
    widget.output->moveCursor(QTextCursor::End);
    widget.output->insertPlainText("st=");
    widget.output->insertPlainText(QString::fromUtf8(to_string(c.st).c_str()));
    widget.output->setTextCursor(cursor);
    delete[](c.f);
    delete[](c.x);
}

void MainWindow::computeNormalCoeffns() {
    bool ableToCompute = true;
    Components c = normalParse();
    c.a = new (nothrow) long double*[4];
    for (int i = 0; i < 4 && ableToCompute; ++i) {
        c.a[i] = new (nothrow) long double[c.n+1];
        if (c.a[i] == NULL)
            ableToCompute = false;
    }
    if (!ableToCompute) {
        printHardwareProblem();
        return;
    } else if (c.st == -2) {
        printWrongInput();
        return;
    }
    NormalArithmetics::naturalSplineConeffns(c.n, c.x, c.f, c.a, c.st);
    if (c.st == -1) {
        printHardwareProblem();
        return;
    }
    stringstream out;
    out<< setprecision(14) << scientific;
    for (int j = 0; j < c.n; ++j) 
        for (int i = 0; i < 4; ++i){;           
            out << "a[" << i << "," <<(j) << "]="<< c.a[i][j] <<",\n";
        }
    out << "st="<<(c.st);
    widget.output->setPlainText(QString::fromStdString(out.str()));
    //widget.output->setCursor(QTextCursor::End);
    if(c.f != NULL) delete[](c.f);
    if(c.x != NULL) delete[](c.x);
   for (int i = 0; i < 4; ++i)
        if(c.a[i] != NULL) delete[](c.a[i]);
    if(c.a != NULL)delete[](c.a);
}

void MainWindow::computeIntervalValue() {
    IntervalComponents c = intervalParse();
    if (c.st == -1) {
        printHardwareProblem();
        return;
    } else if (c.st == -2) {
        printWrongInput();
        return;
    }
    Interval<long double> res;
    try{
    res = IntervalArithmetic::naturalSplineValue(c.n, c.x, c.f, c.xx, c.st);
    }catch(...){
        printWrongArgument();
        return;
    }
    if (c.st == -1) {
        printHardwareProblem();
        return;
    }
    ostringstream out;
    out << setprecision(14) << scientific;
    out << "[" << res.a << " , " << res.b << "] w=" << res.GetWidth() << endl << "st=" << c.st;
    string str = out.str();
    out.clear();
    widget.output->setPlainText(QString::fromUtf8(str.c_str()));
    delete[](c.f);
    delete[](c.x);
}

void MainWindow::computeIntervalCoeffns() {
    bool ableToCompute = true;
    IntervalComponents c = intervalParse();
    c.a = new (nothrow) Interval<long double>*[4];
    for (int i = 0; i < 4 && ableToCompute; ++i) {
        c.a[i] = new (nothrow) Interval<long double>[c.n + 1];
        if (c.a[i] == NULL)
            ableToCompute = false;
    }
    if (!ableToCompute) {
        printHardwareProblem();
        return;
    } else if (c.st == -2) {
        printWrongInput();
        return;
    }
    try{
    IntervalArithmetic::naturalSplineConeffns(c.n, c.x, c.f, c.a, c.st);
    }catch(...){
        printWrongArgument();
        return;
    }
    if (c.st == -1) {
        printHardwareProblem();
        return;
    }
    ostringstream out;
    out << setprecision(14) << scientific;
    for (int j = 0; j <= c.n; ++j) 
        for (int i = 0; i < 4; ++i){
            out << "a[" << i << "," << j << "]=" << "[" << c.a[i][j].a << " , " << c.a[i][j].b << "] w=" << c.a[i][j].GetWidth()<< endl;
        }
    out << "st=" << c.st;
    string str = out.str();
    widget.output->setPlainText(out.str().c_str());
    delete[](c.f);
    delete[](c.x);
    for (int i = 0; i < 4; ++i)
        delete[](c.a[i]);
    delete[](c.a);
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
    Components result;
    QStringList xList = widget.xIn->text().trimmed().split(" ");
    QStringList fList = widget.fIn->text().trimmed().split(" ");
    if (xList.size() != fList.size()) {
        result.st = -2;
        return result;
    }
    result.n = xList.size() - 1;
    result.x = new (nothrow) long double[result.n + 1];
    result.f = new (nothrow) long double[result.n + 1];
    result.st = 0;
    if (result.x == NULL || result.f == NULL) {
        result.st = -1;
        return result;
    }
    for (int i = 0; i < xList.size(); ++i) {
        if (!is_number(xList[i]) || !is_number(fList[i])) {
            result.st = -2;
            return result;
        }
        result.x[i] = Interval<long double>::IntRead(xList[i].toStdString()).a;
        result.f[i] = Interval<long double>::IntRead(fList[i].toStdString()).a;

    }
    result.xx = Interval<long double>::IntRead(widget.pointIn->text().trimmed().toStdString()).a;
    return result;
}

IntervalComponents MainWindow::intervalParse() {
    IntervalComponents* iresult;
    QStringList xList = widget.xIn->text().trimmed().split(" ");
    QStringList fList = widget.fIn->text().trimmed().split(" ");
    iresult = new IntervalComponents;
    (*iresult).n = xList.size() - 1;
    (*iresult).x = new (nothrow) Interval<long double>[(*iresult).n + 1];
    (*iresult).f = new (nothrow) Interval<long double>[(*iresult).n + 1];
    (*iresult).st = 0;
    if ((*iresult).x == NULL || (*iresult).f == NULL) {
        (*iresult).st = -1;
        return *iresult;
    }
    for (int i = 0; i < xList.size(); ++i) {
        QStringList xInterval = xList[i].trimmed().split(",");
        QStringList fInterval = xList[i].trimmed().split(",");
        if (xInterval.size() != 2 || fInterval.size() != 2 || xInterval.size() == 0) {
            (*iresult).st = -2;
            return *iresult;
        }

        if (!is_number(xInterval[0]) || !is_number(xInterval[1]) || !is_number(fInterval[0]) || !is_number(fInterval[1])) {
            (*iresult).st = -2;

            return *iresult;
        }
        (*iresult).x[i].a = Interval<long double>::LeftRead(xInterval[0].toStdString());
        (*iresult).x[i].b = Interval<long double>::RightRead(xInterval[1].toStdString());
        (*iresult).f[i].a = Interval<long double>::LeftRead(fInterval[0].toStdString());
        (*iresult).f[i].b = Interval<long double>::RightRead(fInterval[1].toStdString());
    }
    return *iresult;
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
void MainWindow::printWrongArgument(){
    widget.output->setPlainText("Result unreachable for given arguments.");
}