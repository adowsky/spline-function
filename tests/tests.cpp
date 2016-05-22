#include <iostream>
#ifndef TESTS
#define TESTS
class Tests{
public:
    static bool fail(){
        return false;
    }

    static bool success(){
        return true;
    }
};
#endif


