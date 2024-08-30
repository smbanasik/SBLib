#include "../containers/array.hpp"
#include "../algorithms/data_manip.hpp"

#include <string>

#pragma warning(disable : 4200)

static bool test_initialization() {

    int prim_arr[5] = { 1, 2, 3, 4, 5 };

    auto test = SB_LIB::arr_from_carray<int, 5>(prim_arr, 5);

    for (int i = 0; i < 5; i++) {
        if (test.at(i) != prim_arr[i])
            return false;
        if (test.at(i) != i + 1)
            return false;
    }

    SB_LIB::Array<int, 20> test_empty;

    for (int i = 0; i < test_empty.size(); i++) {
        if (test_empty[i] != 0)
            return false;
    }

    SB_LIB::Array<std::string, 3> string_filled("sample_str");

    for (int i = 0; i < string_filled.size(); i++) {
        if (string_filled[i] != "sample_str")
            return false;
    }

    SB_LIB::Array<std::string, 3> string_arr{"Trying to initialize", "Initializing", "yep!"};

    if (string_arr[2] != "yep!")
        return false;
    
    // TODO: copy constructor test
    // TODO: copy assignment test

    return true;
}

static bool test_access() {

    SB_LIB::Array<int, 20> arr;

    arr.at(0) = 20;
    if (arr.at(0) != 20)
        return false;

    arr[1] = 30;
    if (arr[1] != 30)
        return false;

    try {
        arr[500];
        return false;
    }
    catch (...) {

    }

    arr.f_at(19) = 500;

    if (arr.front() != 20)
        return false;

    if (arr.back() != 500)
        return false;

    int* data = arr.data();

    if (data[19] != 500)
        return false;

    const SB_LIB::Array<int, 5> arr_two(90);

    int test = arr_two.at(1);

    if (test != 90)
        return false;

    return true;
}

static bool test_iterator() {

    SB_LIB::Array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SB_LIB::Array<int, 10>::Iterator arr_it(&arr.at(0));

    auto arr_end = arr.begin();
    arr_end = arr.end();

    if (*(arr_it++) != 1)
        return false;

    if (*(arr_it) != 2)
        return false;

    if (*(++arr_it) != 3)
        return false;

    auto new_it = arr_it.get_next();

    if (*new_it != 4)
        return false;

    auto prev_it = new_it.get_prev();

    if (arr_it != prev_it)
        return false;

    if (arr_it > new_it)
        return false;

    new_it--;

    if (arr_it < --new_it)
        return false;

    if (arr_it[2] != *(arr_it + 2))
        return false;

    arr_it += 2;

    if (*arr_it != 5)
        return false;

    arr_it = 2 + arr_it;

    return true;
}

static bool test_reviterator() {
    // TODO: test all reverse iterator operations
    return true;
}

static bool test_query_operators() {
    
    SB_LIB::Array<int, 5> arr_one;
    SB_LIB::Array<int, 0> arr_two;

    if (arr_one.empty() == true)
        return false;

    if (arr_two.empty() == false)
        return false;

    if (arr_one.size() != arr_one.max_size())
        return false;

    SB_LIB::Array<int, 5> arr_three;

    if (arr_one != arr_three)
        return false;

    arr_one.at(1) = 1;

    if (arr_one == arr_three)
        return false;

    if (arr_one < arr_three)
        return false;

    arr_three.at(1) = 2;

    if (arr_one > arr_three)
        return false;

    return true;
}

static bool test_manipulation() {

    // TODO: subarray

    // TODO: fill
    
    // TODO: swap
    return true;
}

static bool test_algorithms() {
    // TODO: copy and swap
    return true;
}

static int use_counter(int& counter) {
    return counter++;
}

const int NUM_TESTS = 7;
bool run_array_suite() {
    bool all_passed = true;
    
    bool tests[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; i++)
        tests[i] = false;

    int counter = 0;
    
    tests[use_counter(counter)] = test_initialization();
    tests[use_counter(counter)] = test_access();
    tests[use_counter(counter)] = test_iterator();
    tests[use_counter(counter)] = test_reviterator();
    tests[use_counter(counter)] = test_query_operators();
    tests[use_counter(counter)] = test_manipulation();
    tests[use_counter(counter)] = test_algorithms ();

    for (int i = 0; i < NUM_TESTS; i++) {
        all_passed = all_passed && tests[i];
    }

    return all_passed;
}