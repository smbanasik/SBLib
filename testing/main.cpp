#include "../types.hpp"
#include "../containers/array.hpp"
#include "../algorithms/data_manip.hpp"

#include <iostream>
#include <string>

int main() {
    
    SB_LIB::Array<std::string, 10> test("a");

    auto new_test = test.subarray<5>(0, 5);

    std::cout << test.size() << "\n";

    std::cout << test.at(4) << "\n";


    int nums[5] = { 0, 1, 2, 3, 4 };

    auto nums_arr = SB_LIB::Array<int, 5>::from_carray(nums, 5);

    for (int i = 0; i < 5; i++) {
        std::cout << nums_arr[i] << " ";
    }

    SB_LIB::Array<int, 5> new_nums;

    SB_LIB::Array<int, 5>::Iterator it = nums_arr[0], it2 = new_nums[0], it_end = nums_arr.back();

    SB_LIB::copy(it, it_end, it2);

    for (int i = 0; i < 5; i++) {
        std::cout << new_nums[i] << " ";
    }
}