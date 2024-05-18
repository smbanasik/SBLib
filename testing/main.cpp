#include "../types.hpp"
#include "../containers/array.hpp"

#include <iostream>

int main() {
    
    SB_LIB::Array<int, 10> test;

    std::cout << test.size();

}