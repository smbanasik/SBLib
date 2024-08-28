#define NORMAL_TESTING
#ifdef NORMAL_TESTING
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

    SB_LIB::Array<int, 5>::Iterator it = nums_arr.begin(), it2 = new_nums.begin(), it_end = nums_arr.end();
    
    SB_LIB::copy(it, it_end, it2);

    for (int i = 0; i < 5; i++) {
        std::cout << new_nums[i] << " ";
    }
}
#endif



#ifdef SIZE_TEST_MAIN
#include <iostream>
#include <string>
#include <climits>

int main() {

    std::cout << __DATE__ << "::" << __TIME__ << "::" << __FILE__ << "\n";
    std::cout << "CHAR_BIT: " << CHAR_BIT << "\n";
    std::cout << "Pointer size: " << sizeof(int*) << "\n";
    std::cout << "Char size: " << sizeof(char) << "\n";
    std::cout << "Short size: " << sizeof(short) << "\n";
    std::cout << "Int size: " << sizeof(int) << "\n";
    std::cout << "Long size: " << sizeof(long) << "\n";
    std::cout << "Long long size: " << sizeof(long long) << "\n";
    std::cout << "---------------\n";
    std::cout << "UCHAR_MAX: " << UCHAR_MAX << "\n";
    std::cout << "USHRT_MAX: " << USHRT_MAX << "\n";
    std::cout << "UINT_MAX: " << UINT_MAX << "\n";
    std::cout << "ULONG_MAX: " << ULONG_MAX << "\n";
    std::cout << "ULLONG_MAX: " << ULLONG_MAX << "\n";
    std::cout << "---------------\n";

#ifdef _WIN32
    std::cout << "Operating on Windows 32 or 64 \n";
#endif
#ifdef _WIN64
    std::cout << "Operating on Windows 64 \n";
#endif
#ifdef __GNUC__
    std::cout << "Using GCC version" << __GNUC__ << "\n";
    std::cout << "__SIZEOF_POINTER__: " << __SIZEOF_POINTER__ << "\n";
    std::cout << "__SIZEOF_SHORT__: " << __SIZEOF_SHORT__ << "\n";
    std::cout << "__SIZEOF_INT__: " << __SIZEOF_INT__ << "\n";
    std::cout << "__SIZEOF_LONG__: " << __SIZEOF_LONG__ << "\n";
    std::cout << "__SIZEOF_LONG_LONG__: " << __SIZEOF_LONG_LONG__ << "\n";

#endif
    return 0;
}
#endif