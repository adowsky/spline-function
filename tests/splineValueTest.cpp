#include <stdlib.h>
#include <iostream>
#include "NormalArithmetics.h"
#include "tests.cpp"

/*
 * Simple C++ Test Suite
 */
class NormalSplineValueTest{
    static constexpr long double epsilon = 1e-14;
public:
    static void normalSplineValuesTest1() {
        cout<<"NormalSplineValueTest1 ";
        
        long double x[] = {17.0, 20.0, 23.0, 24.0, 25.0, 27.0, 27.7};
        long double f[] = {4.5, 7.0, 6.1, 5.6, 5.8, 5.2, 4.1}; 
        int st = 0;
        long double result = NormalArithmetics::naturalSplineValue(6,x, f, 23.5,st);
        result = 5.78458659669145e+0000 - result;
        
        if(result<0)
            result = -result;
        if(result<epsilon && st == 0){
            Tests::success();
        }else
            Tests::fail();
    }

    static void normalSplineValueTest2() {
        cout<<"NormalSplineValueTest2 ";
        long double x[] = {0.00,1.0};
        long double f[] = {0.0,1.0}; 
        int st = 0;
        long double result = NormalArithmetics::naturalSplineValue(1,x, f, 0.5,st);
        if((result - 5.000e-0001) < epsilon && st == 0){
            Tests::success();
        }else
            Tests::fail();
    }
    static void normalSplineValueTest3(){
        cout<<"NormalSplineValueTest3 ";
        long double x[] = {0.0,1.0};
        long double f[] = {0.0,1.0}; 
        int st = 0;
        long double result = NormalArithmetics::naturalSplineValue(1,x, f, 2.0,st);
        if(st == 3){
            Tests::success();
        }else
            Tests::fail();
    }
};