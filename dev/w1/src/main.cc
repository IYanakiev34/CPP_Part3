#include <iostream>
#include <string>
#include "1/add.h"
#include "1/pu.h"
#include "2/as.h"
#include "3/rawCapacity.h"
#include "5/storage.h"
#include "5/tcp_udp.h"
#include "5/icmp.h"

void fun();


int main(int argc, char **argv)
{

    // Exercise 1
    /* PointerUnion pu = { add };

    fun();

    std::cout << pu.vp << '\n';
    */

    // Exercise 2
    /*
    int chVal = 'x';
    std::cout << as<char>(chVal) << '\n';
    */ 
    
    // Exercise 3
    /*
    std::size_t const size =10;
    // Allocate space for 10 strings
    std::string *arr = rawCapacity<std::string>(size);
    // put one string
    new (arr+1) std::string {"Hello from my custom new\n"};
    std::cout << arr[1];

    // manually delete it + the buffer
    arr[1].std::string::~string();
    operator delete(arr);
    */

    // Exercise 5
    Storage storage({1,2,3,4});

    std::cout << storage[Icmp::SRC] << "\n";
    return 0;
}