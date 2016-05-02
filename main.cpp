
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
using namespace std;
using namespace interval_arithmetic;
void runTests(){
    cout<<"***TESTS START***"<<endl;
    NormalSplineValueTest::runAllTests();
    SplineCoeffnsTest::runAllTests();
    std::cout << "***TESTS END***" << std::endl;
}
int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

 //  

    // create and show your widgets here
    //runTests();
          
     QApplication app(argc, argv);
     MainWindow window;
     window.show(); 
     return app.exec();
}

