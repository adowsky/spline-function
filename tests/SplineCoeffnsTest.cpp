#ifndef SPLINECOEFFNSTEST
#define SPLINECOEFFNSTEST
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "NormalArithmetics.h"
#include "tests.cpp"
#include "IntervalArithmetic.h"

using namespace std;
using namespace interval_arithmetic;

class SplineCoeffnsTest {
    static constexpr long double epsilon = 4e-14;

    static Interval<long double> readInterval(long double val) {
        stringstream ss;
        ss.precision(14);
        ss << scientific << val;
        return Interval<long double>::IntRead(ss.str());

    }
public:
    static void splineCoeffnsTest1() {
        cout << "splineCoeffnsTest1 ";
        long double x[] = {17, 20, 23, 24, 25, 27, 27.7};
        long double f[] = {4.5, 7.0, 6.1, 5.6, 5.8, 5.2, 4.1};
        long double** a = new long double*[4];
        for (int i = 0; i < 4; ++i) {
            a[i] = new long double[7];
        }
        int st = 0;
        NormalArithmetics::naturalSplineConeffns(6, x, f, a, st);
        long double results[4][7];
        results[0][0] = 1.34403218971898e+0002;
        results[1][0] = -2.51355662208450e+0001;
        results[2][0] = 1.54360591755605e+0000;
        results[3][0] = -3.02667826971775e-0002;
        results[0][1] = -3.10994943085215e+0002;
        results[1][1] = 4.16741580877220e+0001;
        results[2][1] = -1.79688029787230e+0000;
        results[3][1] = 2.54079875599616e-0002;
        results[0][2] = -2.47891739586384e+0003;
        results[1][2] = 3.24446651928412e+0002;
        results[2][2] = -1.40913365518154e+0001;
        results[3][2] = 2.03588512979426e-0001;
        results[0][3] = 3.52170451311799e+0003;
        results[1][3] = -4.25631086694317e+0002;
        results[2][3] = 1.71619025574650e+0001;
        results[3][3] = -2.30484252427246e-0001;
        results[0][4] = 1.31583779039557e+0003;
        results[1][4] = -1.60927079967626e+0002;
        results[2][4] = 6.57374228839740e+0000;
        results[3][4] = -8.93087821730107e-0002;
        results[0][5] = -6.63063461573241e+0003;
        results[1][5] = 7.22014298491039e+0002;
        results[2][5] = -2.61277902471087e+0001;
        results[3][5] = 3.14413841722126e-0001;
        bool result = true;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 4; ++j) {

                long double val = results[j][i] - a[j][i];
                if (val < 0)
                    val = -val;
                long double tmp = results[j][i];
                if(tmp<0)
                    tmp = -tmp;
                long double localEpsilon = epsilon;
                while(tmp>=10){
                    tmp/=10;
                    localEpsilon *= 10;
                }
                result = result && val <= localEpsilon;
                if (!result) {
                    break;


                }
            }
        for (int i = 0; i < 4; ++i) {
            delete[](a[i]);
        }
        delete[] (a);
        if (st == 0 && result)
            Tests::success();
        else
            Tests::fail();
    }

    static void intervalSplineCoeffnsTest1() {
        cout << "intervalSplineCoeffnsTest1 ";

        Interval<long double> x[] = {readInterval(17), readInterval(20), readInterval(23), readInterval(24), readInterval(25),
            readInterval(27), readInterval(27.7)};
        Interval<long double> f[] = {readInterval(4.5), readInterval(7.0), readInterval(6.1),
            readInterval(5.6), readInterval(5.8), readInterval(5.2), readInterval(4.1)};
        Interval<long double>** a = new Interval<long double>*[4];
        for (int i = 0; i < 4; ++i) {
            a[i] = new Interval<long double>[7];
        }
        int st = 0;
        IntervalArithmetic::naturalSplineConeffns(6, x, f, a, st);
        Interval<long double> results[4][7];
        results[0][0] = readInterval(1.34403218971898e+0002);
        results[1][0] = readInterval(-2.51355662208450e+0001);
        results[2][0] = readInterval(1.54360591755605e+0000);
        results[3][0] = readInterval(-3.02667826971775e-0002);
        results[0][1] = readInterval(-3.10994943085215e+0002);
        results[1][1] = readInterval(4.16741580877220e+0001);
        results[2][1] = readInterval(-1.79688029787230e+0000);
        results[3][1] = readInterval(2.54079875599616e-0002);
        results[0][2] = readInterval(-2.47891739586384e+0003);
        results[1][2] = readInterval(3.24446651928412e+0002);
        results[2][2] = readInterval(-1.40913365518154e+0001);
        results[3][2] = readInterval(2.03588512979426e-0001);
        results[0][3] = readInterval(3.52170451311799e+0003);
        results[1][3] = readInterval(-4.25631086694317e+0002);
        results[2][3] = readInterval(1.71619025574650e+0001);
        results[3][3] = readInterval(-2.30484252427246e-0001);
        results[0][4] = readInterval(1.31583779039557e+0003);
        results[1][4] = readInterval(-1.60927079967626e+0002);
        results[2][4] = readInterval(6.57374228839740e+0000);
        results[3][4] = readInterval(-8.93087821730107e-0002);
        results[0][5] = readInterval(-6.63063461573241e+0003);
        results[1][5] = readInterval(7.22014298491039e+0002);
        results[2][5] = readInterval(-2.61277902471087e+0001);
        results[3][5] = readInterval(3.14413841722126e-0001);
        
        bool result = true;
        
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 4; ++j) {
                long double val = results[j][i].a - a[j][i].a;
                if (val < 0)
                    val = -val;
                long double tmp = results[j][i].a;
                if(tmp<0)
                    tmp = -tmp;
                long double localEpsilon = epsilon;
                while(tmp>=10){
                    tmp/=10;
                    localEpsilon *= 10;
                }
                result = result && val <= localEpsilon;
                if (!result) {
                    break;


                }
            }
            for (int i = 0; i < 4; ++i) {
            delete[](a[i]);
        }
        delete[] (a);
        if (st == 0 && result)
            Tests::success();
        else
            Tests::fail();
    }
    
    static void intervalSplineCoeffnsTest2(){
        cout << "intervalSplineCoeffnsTest2 ";

        Interval<long double> x[] = {readInterval(0), readInterval(1)};
        Interval<long double> f[] = {readInterval(0), readInterval(1)};
        Interval<long double>** a = new Interval<long double>*[4];
        for (int i = 0; i < 4; ++i) {
            a[i] = new Interval<long double>[1];
        }
        int st = 0;
        IntervalArithmetic::naturalSplineConeffns(1, x, f, a, st);
        Interval<long double> results[4][1];
        results[0][0] = readInterval(0.0e+000);
        results[1][0] = readInterval(1.00000000000000e+0000);
        results[2][0] = readInterval(0.0e+0000);
        results[3][0] = readInterval(0.0e+0000);        
        bool result = true;
        cout.precision(14);
        for (int i = 0; i < 1; ++i)
            for (int j = 0; j < 4; ++j) {
                long double val = results[j][i].a - a[j][i].a;
                if (val < 0)
                    val = -val;
                long double tmp = results[j][i].a;
                if(tmp<0)
                    tmp = -tmp;
                long double localEpsilon = epsilon;
                while(tmp>=10){
                    tmp/=10;
                    localEpsilon *= 10;
                }
                result = result && val <= localEpsilon;
                if (!result) {
                    break;
                }
            }
            for (int i = 0; i < 4; ++i) {
            delete[](a[i]);
        }
        delete[] (a);
        if (st == 0 && result)
            Tests::success();
        else
            Tests::fail();
    }
    
        static void intervalSplineCoeffnsTest3(){
        cout << "intervalSplineCoeffnsTest3 ";

        Interval<long double> x[] = {readInterval(0), readInterval(1),readInterval(2)};
        Interval<long double> f[] = {readInterval(0), readInterval(1), readInterval(2)};
        Interval<long double>** a = new Interval<long double>*[4];
        for (int i = 0; i < 4; ++i) {
            a[i] = new Interval<long double>[2];
        }
        int st = 0;
        IntervalArithmetic::naturalSplineConeffns(2, x, f, a, st);
        Interval<long double> results[4][2];
        results[0][0] = readInterval(0.0e+000);
        results[1][0] = readInterval(1.00000000000000e+0000);
        results[2][0] = readInterval(0.0e+0000);
        results[3][0] = readInterval(0.0e+0000);    
        results[0][1] = readInterval(0.0e+000);
        results[1][1] = readInterval(1.00000000000000e+0000);
        results[2][1] = readInterval(0.0e+0000);
        results[3][1] = readInterval(0.0e+0000);  
        bool result = true;
        cout.precision(14);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 4; ++j) {
                long double val = results[j][i].a - a[j][i].a;
                if (val < 0)
                    val = -val;
                long double tmp = results[j][i].a;
                if(tmp<0)
                    tmp = -tmp;
                long double localEpsilon = epsilon;
                while(tmp>=10){
                    tmp/=10;
                    localEpsilon *= 10;
                }
                result = result && val <= localEpsilon;
                if (!result) {
                    break;


                }
            }
            for (int i = 0; i < 4; ++i) {
            delete[](a[i]);
        }
        delete[] (a);
        if (st == 0 && result)
            Tests::success();
        else
            Tests::fail();
    }
        static void intervalSplineCoeffnsTest4(){
        cout << "intervalSplineCoeffnsTest4";

        Interval<long double> x[] = {readInterval(0), readInterval(0),readInterval(2)};
        Interval<long double> f[] = {readInterval(0), readInterval(1), readInterval(2)};
        Interval<long double>** a = new Interval<long double>*[4];
        for (int i = 0; i < 4; ++i) {
            a[i] = new Interval<long double>[2];
        }
        int st = 0;
        IntervalArithmetic::naturalSplineConeffns(2, x, f, a, st);
        for (int i = 0; i < 4; ++i) {
            delete[](a[i]);
        }
        delete[] (a);
        if (st == 2)
            Tests::success();
        else
            Tests::fail();
    }
        
        
    static void runAllTests() {
        splineCoeffnsTest1();
        intervalSplineCoeffnsTest1();
        intervalSplineCoeffnsTest2();
        intervalSplineCoeffnsTest3();
    }

    
};
#endif

