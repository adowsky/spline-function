#ifndef SPLINEVALUETEST
#define SPLINEVALUETEST
#include <stdlib.h>
#include <iostream>
#include "NormalArithmetics.h"
#include "tests.cpp"
#include "interval.h"
#include "IntervalArithmetic.h"

using namespace std;
using namespace interval_arithmetic;

class NormalSplineValueTest {
    static constexpr long double epsilon = 1e-14;
public:

    static void normalSplineValuesTest1() {
        cout << "NormalSplineValueTest1 ";
        long double x[] = {17.0, 20.0, 23.0, 24.0, 25.0, 27.0, 27.7};
        long double f[] = {4.5, 7.0, 6.1, 5.6, 5.8, 5.2, 4.1};
        int st = 0;
        long double result = NormalArithmetics::naturalSplineValue(6, x, f, 23.5, st);
        result = 5.78458659669145e+0000 - result;
        if (result < 0)
            result = -result;
        if (result < epsilon && st == 0) {
            Tests::success();
        } else
            Tests::fail();
    }

    static void normalSplineValueTest2() {
        cout << "NormalSplineValueTest2 ";
        long double x[] = {0.00, 1.0};
        long double f[] = {0.0, 1.0};
        int st = 0;
        long double result = NormalArithmetics::naturalSplineValue(1, x, f, 0.5, st);
        if ((result - 5.000e-0001) < epsilon && st == 0) {
            Tests::success();
        } else
            Tests::fail();
    }

    static void normalSplineValueTest3() {
        cout << "NormalSplineValueTest3 ";
        long double x[] = {0.0, 1.0};
        long double f[] = {0.0, 1.0};
        int st = 0;
        long double result = NormalArithmetics::naturalSplineValue(1, x, f, 2.0, st);
        if (st == 3) {
            Tests::success();
        } else
            Tests::fail();
    }

    static void intervalSplineValueTest1() {
        cout << "IntervalSplineValueTest1 ";

        Interval<long double> x[] = {Interval<long double>::IntRead("17.0"), Interval<long double>::IntRead("20.0"),
            Interval<long double>::IntRead("23.0"), Interval<long double>::IntRead("24.0"),
            Interval<long double>::IntRead("25.0"), Interval<long double>::IntRead("27.0"), Interval<long double>::IntRead("27.7")};
        Interval<long double> f[] = {Interval<long double>::IntRead("4.5"), Interval<long double>::IntRead("7.0"),
            Interval<long double>::IntRead("6.1"), Interval<long double>::IntRead("5.6"), Interval<long double>::IntRead("5.8"),
            Interval<long double>::IntRead("5.2"), Interval<long double>::IntRead("4.1")};

        int st = 0;
        Interval<long double> res = IntervalArithmetic::naturalSplineValue(6, x, f, Interval<long double>::IntRead("23.5,st"), st);
        long double result = 5.78458659669145e+0000 - res.a;
        if (result < 0)
            result = -result;
        if (result < epsilon && st == 0) {
            Tests::success();
        } else
            Tests::fail();
    }

    static void intervalSplineValueTest2() {
        cout << "IntervalSplineValueTest2 ";
        Interval<long double> x[] = {Interval<long double>::IntRead("0.0"), Interval<long double>::IntRead("1.0")};

        Interval<long double> f[] = {Interval<long double>::IntRead("0.0"), Interval<long double>::IntRead("1.0")};
        int st = 0;
        Interval<long double> result = IntervalArithmetic::naturalSplineValue(1, x, f, Interval<long double>::IntRead("0.5"), st);

        if ((result.a - 5.000e-0001) < epsilon && st == 0) {
            Tests::success();
        } else
            Tests::fail();
    }

    static void intervalSplineValueTest3() {
        cout << "IntervalSplineValueTest3 ";
        Interval<long double> x[] = {Interval<long double>::IntRead("0.0"), Interval<long double>::IntRead("1.0")};

        Interval<long double> f[] = {Interval<long double>::IntRead("0.0"), Interval<long double>::IntRead("1.0")};
        int st = 0;
        Interval<long double> result = IntervalArithmetic::naturalSplineValue(1, x, f, Interval<long double>::IntRead("2.0"), st);
        if (st == 3) {
            Tests::success();
        } else
            Tests::fail();
    }

    static void runAllTests() {
        normalSplineValuesTest1();
        normalSplineValueTest2();
        normalSplineValueTest3();
        intervalSplineValueTest1();
        intervalSplineValueTest2();
        intervalSplineValueTest3();
    }
};
#endif