
#include "NormalArithmetics.h"
#include <iostream>
using namespace std;

long double NormalArithmetics::naturalSplineValue(int n, long double* x, long double* f, long double xx, int& st) {
    int i,k;
    long double u,y,z;
    bool found;
    long double a[4];
    long double *d = new (nothrow) long double[n+1];
    long double *b = new (nothrow) long double[n];
    long double *c = new (nothrow) long double[n];
    if(d == NULL || b == NULL || c == NULL){
        st = -1;
        return 0;
    }
    long double result = 0;
    if(n<1)
        st = 1;
    else if ((xx<x[0]) || (xx>x[n]))
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
    if(st == 0){ // if data is valid
        d[0] = 0.0;
        d[n] = 0.0;
        if(n>1){
            z = x[2];
            y = z - x[1];
            z = z - x[0];
            u = f[1];
            b[1] = y/z;
            d[1] = 6*((f[2]-u)/y-(u-f[0])/(x[1]-x[0]))/z;
            z = x[n-2];
            y = x[n-1] - z;
            z = x[n] - z;
            u = f[n-1];
            c[n-1] = y/z;
            d[n-1] = 6*((f[n]-u)/(x[n]-x[n-1])-(u-f[n-2])/y)/z;
            for(i=2; i<=n-2; i++){
                z = x[i];
                y = x[i+1] - z;
                z = z - x[i-1];
                u = f[i];
                b[i] = y/(y+z);
                c[i] = 1 - b[i];
                d[i] = 6*((f[i+1]-u)/y-(u-f[i-1])/z)/(y+z);
            }
            u = 2;
            i = 0;
            y = d[1] / u;
            d[1] = y;
            if(n > 2){
                do{
                    i = i + 1;
                    z = b[i] / u;
                    b[i] = z;
                    u = 2-z*c[i+1];
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
            if(xx>x[i] && xx<=x[i+1])
                found = true;
            
        }while(!found);
        y = x[i+1] - x[i];
        z = d[i+1];
        u = d[i];
        a[0] = f[i];
        a[1] = (f[i+1]-f[i])/y-(2*u+z)*y/6;
        a[2] = u/2;
        a[3] = (z-u)/(6*y);
        y = a[3];
        z = xx-x[i];
        for(i=2; i>=0;i--){
            y = y*z+a[i];
        }
        result = y;
    }
    return result;
}

void NormalArithmetics::naturalSplineConeffns(int n, long double* x, long double* f, long double** a, int& st){
    int i,k;
    long double u,v,y,z,xi;
    long double* d = new (nothrow) long double[n+1];
    long double* b = new (nothrow) long double[n-1];
    long double* c = new (nothrow) long double[n];
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
    if(st == 0){
        d[0] = 0.0;
        d[n] = 0.0;
        if(n>1){
            z = x[2];
            y = z - x[1];
            z = z - x[0];
            u = f[1];
            b[1] = y/z;
            d[1] = 6*((f[2]-u)/y-(u-f[0])/(x[1]-x[0]))/z;
            z = x[n-2];
            y = x[n-1] - z;
            z = x[n] - z;
            u = f[n-1];
            c[n-1] = y/z;
            d[n-1] = 6*((f[n]-u)/(x[n]-x[n-1])-(u-f[n-2])/y)/z;
            for(i=2;i<=n-2;++i){
                z = x[i];
                y = x[i+1] - z;
                z = z - x[i-1];
                u = f[i];
                b[i] = y/(y+z);
                c[i] = 1 - b[i];
                d[i] = 6*((f[i+1]-u)/y-(u-f[i-1])/z)/(y+z);
            }
            u = 2.0;
            i = 0;
            y = d[1]/u;
            d[1] = y;
            if(n>2)
                do{
                   i++;
                   z = b[i]/u;
                   b[i] = z;
                   u = 2-z*c[i+1];
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
            v = (f[i+1]-u)/z-(2*y+d[i+1])*z/6;
            z = (d[i+1]-y)/(6*z);
            y = y/2;
            a[0][i] = ((-z*xi+y)*xi-v)*xi+u;
            u = 3*z*xi;
            a[1][i] = (u-2*y)*xi+v;
            a[2][i] = y-u;
            a[3][i] = z;
        }            
    }
       
}