/* 
 * File:   MainWindow.h
 * Author: adowsky
 *
 * Created on March 13, 2016, 11:44 AM
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H
#include <QDialog>
#include "ui_MainWindow.h"
#include "interval.h"
#include "NormalArithmetics.h"
#include "IntervalArithmetic.h"
#include <cstdlib>
#include <regex>
#include <sstream>
#include <qt4/QtCore/qstring.h>
#include <qt4/QtGui/qtextedit.h>

enum Arithmetic{
    NORMAL, INTERVAL
};

enum Target{
    COEFF, VALUE
};
struct Components{
    bool filled;
    bool coef;
    int n;
    long double* x;
    long double* f;
    long double xx;
    long double** a;
    int st;
};
struct IntervalComponents{
    bool filled;
    bool coef;
    int n;
    interval_arithmetic::Interval<long double>* x;
    interval_arithmetic::Interval<long double>* f;
    interval_arithmetic::Interval<long double> xx;
    interval_arithmetic::Interval<long double>** a;
    int st;
};

class MainWindow : public QDialog {
    Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();
private:
    stringstream out;
    Components normalParse();
    IntervalComponents intervalParse();
    void printHardwareProblem();
    void printWrongInput();
    void printWrongArgument();
    void computeNormalValue();
    void computeNormalCoeffns();
    void computeIntervalValue();
    void computeIntervalCoeffns();
    void parseIntervalPointIn();
    void parseNormalPointIn();
    bool is_number(QString);
    static const QString NORX;
    static const QString NORF;
    static const QString NORVALXX;
    static const QString INX;
    static const QString INF;
    static const QString INVALXX;
    Components normals;
    IntervalComponents intervals;
    Ui::MainWindow widget;
    Arithmetic arit;
    Target target;
    private slots:
        void computeResult();
        void on_normalBtn_clicked();
        void on_intervalBtn_clicked();
        void on_coeffBtn_clicked();
        void on_valueBtn_clicked();
     
};

#endif /* _MAINWINDOW_H */
