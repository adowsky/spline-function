/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NormalArithmetics.h
 * Author: adowsky
 *
 * Created on March 12, 2016, 3:21 PM
 */

#ifndef NORMALARITHMETICS_H
#define NORMALARITHMETICS_H

class NormalArithmetics {
public:
    static long double naturalSplineValue(int,long double*,long double*,long double, int&);
    static void naturalSplineConeffns(int, long double*, long double*, long double**, int&);
private:

};

#endif /* NORMALARITHMETICS_H */

