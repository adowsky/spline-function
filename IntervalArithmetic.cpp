
/* 
 * File:   IntervalArithmetic.cpp
 * Author: adowsky
 * 
 * Created on March 13, 2016, 12:02 AM
 */

#include "IntervalArithmetic.h"

using namespace interval_arithmetic;

Interval<long double> IntervalArithmetic::naturalSplineValue(int n, Interval<long double>* x, Interval<long double>* f, Interval<long double> xx, int& st) {
    int i,k;
    Interval<long double> u,y,z;
    bool found;
    Interval<long double> a[4];
    Interval<long double> *d = new (nothrow) Interval<long double>[n+1];
    Interval<long double> *b = new (nothrow) Interval<long double>[n];
    Interval<long double> *c = new (nothrow) Interval<long double>[n];
    if(d == NULL || b == NULL || c == NULL){
        st = -1;
        return Interval<long double>::IntRead("0");
    }
    Interval<long double> i6 = Interval<long double>::IntRead("6");
    Interval<long double> i2 = Interval<long double>::IntRead("2");
    Interval<long double> i1 = Interval<long double>::IntRead("1");
    Interval<long double> result;
    if(n<1)
        st = 1;
    else if ((xx.a<x[0].a) || (xx.b>x[n].b))
        st = 3;
    else{
        st = 0;
        i = -1;
        //checking if data array contains different values
        do{
            i++;
            for(k=i+1;k<=n;++k){
                if(x[i]==x[k])
                    st = 2;
            }
        }while(i!=n-1 && st != 2);
    }
    try{
    if(st == 0){ // if data is valid
        d[0].a = 0.0;
        d[0].b = 0.0;
        d[n].a = 0.0;
        d[n].b = 0.0;
        if(n>1){
            z = x[2];
            y = z - x[1];
            z = z - x[0];
            u = f[1];
            b[1] = y/z;
            d[1] = i6*((f[2]-u)/y-(u-f[0])/(x[1]-x[0]))/z;
            z = x[n-2];
            y = x[n-1] - z;
            z = x[n] - z;
            u = f[n-1];
            c[n-1] = y/z;
            d[n-1] = i6*((f[n]-u)/(x[n]-x[n-1])-(u-f[n-2])/y)/z;
            for(i=2; i<=n-2; i++){
                z = x[i];
                y = x[i+1] - z;
                z = z - x[i-1];
                u = f[i];
                b[i] = y/(y+z);
                c[i] = i1 - b[i];
                d[i] = i6*((f[i+1]-u)/y-(u-f[i-1])/z)/(y+z);
            }
            u = Interval<long double>::IntRead("2");
            i = 0;
            y = d[1] / u;
            d[1] = y;
            if(n > 2){
                do{
                    i = i + 1;
                    z = b[i] / u;
                    b[i] = z;
                    u = i2-z*c[i+1];
                    y = (d[i+1]-y*c[i+1])/u;
                    d[i+1] = y;
                }while(i != n-2);
            }
        }
        u = d[n-1];
        for(i=n-2; i>=1;i--){
            u = d[i]-u*b[i];
            d[i] = u;
        }
        found = false;
        i = -1;
        do{
            i++;
            if(xx.a>=x[i].a && xx.b<=x[i+1].b)
                found = true;
            
        }while(!found);
        y = x[i+1] - x[i];
        z = d[i+1];
        u = d[i];
        a[0] = f[i];
        a[1] = (f[i+1]-f[i])/y-(i2*u+z)*y/i6;
        a[2] = u/i2;
        a[3] = (z-u)/(i6*y);
        y = a[3];
        z = xx-x[i];
        for(i=2; i>=0;i--){
            y = y*z+a[i];
        }
        result = y;
    }
    }catch(...){
    if(d != NULL) delete[] d;
    if(b != NULL) delete[] b;
    if(c != NULL) delete[] c;
    throw runtime_error("Division by an interval containing 0.");
    }
    if(d != NULL) delete[] d;
    if(b != NULL) delete[] b;
    if(c != NULL) delete[] c;
    return result;
}
void IntervalArithmetic::naturalSplineConeffns(int n, Interval<long double>* x, Interval<long double>* f, Interval<long double>** a, int& st){
    int i,k;
    Interval<long double> u,v,y,z,xi;
    Interval<long double>* d = new (nothrow) Interval<long double>[n+1];
    Interval<long double>* b = new (nothrow) Interval<long double>[n];
    Interval<long double>* c = new (nothrow) Interval<long double>[n];
    
    Interval<long double> i6 = Interval<long double>::IntRead("6.0");
    Interval<long double> i2 = Interval<long double>::IntRead("2.0");
    Interval<long double> i1 = Interval<long double>::IntRead("1.0");
    if(n<1)
        st = 1;
    else{
        st = 0;
        i = -1;
        do{
            i++;
            for(k=i+1;k<=n;++k)
                if(x[i] == x[k])
                    st = 2;
        }while(i != n-1 && st !=2);
    }
    try{
    if(st == 0){
        d[0] = Interval<long double>::IntRead("0.0");
        d[n] = Interval<long double>::IntRead("0.0");
        if(n>1){
            z = x[2];
            y = z - x[1];
            z = z - x[0];
            u = f[1];
            b[1] = y/z;
            d[1] = i6*((f[2]-u)/y-(u-f[0])/(x[1]-x[0]))/z;
            z = x[n-2];
            y = x[n-1] - z;
            z = x[n] - z;
            u = f[n-1];
            c[n-1] = y/z;
            d[n-1] = i6*((f[n]-u)/(x[n]-x[n-1])-(u-f[n-2])/y)/z;
            for(i=2;i<=n-2;++i){
                z = x[i];
                y = x[i+1] - z;
                z = z - x[i-1];
                u = f[i];
                b[i] = y/(y+z);
                c[i] = i1 - b[i];
                d[i] = i6*((f[i+1]-u)/y-(u-f[i-1])/z)/(y+z);
            }
            u = Interval<long double>::IntRead("2.0");
            i = 0;
            y = d[1]/u;
            d[1] = y;
            if(n>2)
                do{
                   i++;
                   z = b[i]/u;
                   b[i] = z;
                   u = i2-z*c[i+1];
                   y = (d[i+1]-y*c[i+1])/u;
                   d[i+1] = y;
                }while(i!=n-2);
        }
        u = d[n-1];
        for(i=n-2;i>=1;--i){
            u = d[i] - u*b[i];
            d[i] = u;
        }
        for(i=0;i<=n-1;i++){
            u = f[i];
            xi = x[i];
            z = x[i+1] - xi;
            y = d[i];
            v = (f[i+1]-u)/z-(i2*y+d[i+1])*z/i6;
            z = (d[i+1]-y)/(i6*z);
            y = y/i2;
            a[0][i] = ((z.Opposite()*xi+y)*xi-v)*xi+u;
            u = Interval<long double>::IntRead("3")*z*xi;
            a[1][i] = (u-(i2*y))*xi+v;
            a[2][i] = y-u;
            a[3][i] = z;
        }            
    }
    }catch(...){
    if(d != NULL) delete[] d;
    if(b != NULL) delete[] b;
    if(c != NULL) delete[] c;
    throw runtime_error("Division by an interval containing 0.");
    }
    if(d != NULL) delete[] d;
    if(b != NULL) delete[] b;
    if(c != NULL) delete[] c;
}