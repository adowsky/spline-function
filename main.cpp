
/*
 * File:   main.cpp
 * Author: adowsky
 *
 * Created on March 12, 2016, 1:43 PM
 */

#include <QApplication>
#include "interval.h"
#include "tests/splineValueTest.cpp"
#include "tests/SplineCoeffnsTest.cpp"
#include "ui_MainWindow.h"
#include "MainWindow.h"
#include "IntervalArithmetic.h"
#include <iostream>

bool runTests(){
    bool result = true;
    result &= NormalSplineValueTest::runAllTests();
    result &= SplineCoeffnsTest::runAllTests();
    return result;
}
int main(int argc, char *argv[]) {
     QApplication app(argc, argv);
     MainWindow window;
     window.show(); 
     return app.exec();
}

