#define NORMAL_TESTING
#ifdef NORMAL_TESTING
#include "test_suite.hpp"

#include <iostream>

int main() {

    bool all_passed = false;

    bool array_passed = run_array_suite();

    all_passed = array_passed;

    std::cout << all_passed;

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