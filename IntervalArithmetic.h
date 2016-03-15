/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntervalArithmetic.h
 * Author: adowsky
 *
 * Created on March 13, 2016, 12:02 AM
 */

#ifndef INTERVALARITHMETIC_H
#define INTERVALARITHMETIC_H

#include "interval.h"
using namespace interval_arithmetic;

class IntervalArithmetic {
public:
static Interval<long double> naturalSplineValue(int, Interval<long double>*,Interval<long double>*,Interval<long double>,int&);
static void naturalSplineConeffns(int, Interval<long double>*, Interval<long double>* , Interval<long double>** , int& );
private:

};

#endif /* INTERVALARITHMETIC_H */

