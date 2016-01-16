#ifndef INC_READTYPE_H
#define INC_READTYPE_H

#include <iostream>
#include <string>
#include <limits>

template <typename T>
T ReadType( const std::string & prompt  ) {
    T n;
    while( (std::cout << prompt) && ! (std::cin>> n) ) {
        std::cout << "Invalid input!\n\n";
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );
    }
    return n;
}
#endif