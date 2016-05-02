#include <iostream>
#ifndef TESTS
#define TESTS
class Tests{
public:
    static void fail(){
        std::cout<<"[FAIL]"<<std::endl;
    }

    static void success(){
        std::cout<<"[OK]"<<std::endl;
    }
};
#endif


