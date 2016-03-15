
#ifndef SPLINECOEFFNSTEST
#define SPLINECOEFFNSTEST
#include <cstdlib>
#include <iostream>
#include "NormalArithmetics.h"
#include "tests.cpp"

using namespace std;


class SplineCoeffnsTest{
    static constexpr long double epsilon = 1e-14;
public:

    static void splineCoeffnsTest1(){
        cout<<"splineCoeffnsTest1 ";
        
        long double x[] = {17, 20, 23, 24, 25, 27, 27.7};
        long double f[] = {4.5, 7.0, 6.1, 5.6, 5.8, 5.2, 4.1}; 
        long double** a = new long double*[4];
        for(int i=0;i<4;++i){
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
        results[0][2] = -2.47891939586384e+0003;
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
        for(int i=0;i<6;++i)
            for(int j=0;j<4;++j){
                int val = results[j][i] - a[j][i];
                if(val< 0)
                    val = -val;
                result = result && val<= epsilon;
                if(!result){
                    break;
                        
                        
                }
            }
        if(st == 0 && result)
            Tests::success();
        else
            Tests::fail();
    }
};
#endif