/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

enum Arithmetic{
    NORMAL, INTERVAL
};

enum Target{
    COEFF, VALUE
};
struct Components{
    int n;
    long double* x;
    long double* f;
    long double xx;
    long double** a;
    int st;
};
struct IntervalComponents{
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
    Components normalParse();
    IntervalComponents intervalParse();
    void printHardwareProblem();
    void printWrongInput();
    void printWrongArgument();
    void computeNormalValue();
    void computeNormalCoeffns();
    void computeIntervalValue();
    void computeIntervalCoeffns();
    bool is_number(QString);
    static const QString NORX;
    static const QString NORF;
    static const QString NORVALXX;
    static const QString INX;
    static const QString INF;
    static const QString INVALXX;
    
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
