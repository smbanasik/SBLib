#include "../types.hpp"
#include "../containers/array.hpp"

#include <iostream>
#include <string>

int main() {
    
    SB_LIB::Array<std::string, 10> test;

    SB_LIB::Array<std::string, 10>::Iterator it;

    std::cout << test.size() << "\n";

    test.at(5) = "gamers";
    test.at(6) = "hahaha";

    it = test.at(5);

    *(--it) = "peepee";

    std::cout << test.at(4);

}