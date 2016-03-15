/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
using namespace std;

void runTests(){
    cout<<"***TESTS START***"<<endl;
    NormalSplineValueTest::normalSplineValuesTest1();
    NormalSplineValueTest::normalSplineValueTest2();
    NormalSplineValueTest::normalSplineValueTest3();
    SplineCoeffnsTest::splineCoeffnsTest1();
    std::cout << "***TESTS END***" << std::endl;
    size_t e;
    std:: cout<<std::stold("0.5", &e)<<std::endl;
}
int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

 //  

    // create and show your widgets here
    runTests();
     QApplication app(argc, argv);
     MainWindow window;
     window.show();
     return app.exec();
}

