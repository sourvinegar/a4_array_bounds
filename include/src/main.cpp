//src/main.cpp
#include "array/array_bounds.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>
int main() {
     int arr[]{2, 5, 5, 5, 10};
     int size{sizeof(arr) / sizeof(arr[0])};

     int target{5};
     // Find the position where target can be inserted
     // while keeping the array sorted.
     auto itr = std::lower_bound(arr, arr + size, target);
     // itr (iterator) points to that position
     // Subtract arr (pointer) from itr (pointer) to get the index
     std::cout << itr - arr << "\n"; // 1
     // target can be inserted at index 1

     target = 3;
     itr = std::lower_bound(arr, arr + size, target);
     std::cout << itr - arr << "\n"; // 1

     target = 0;
     itr = std::lower_bound(arr, arr + size, target);
     std::cout << itr - arr << "\n"; // 0

     target = 8;
     itr = std::lower_bound(arr, arr + size, target);
     std::cout << itr - arr << "\n"; // 4
     
     target = 15;
     itr = std::lower_bound(arr, arr + size, target);
     std::cout << itr - arr << "\n"; // 5

     return 0;


}
/*
int a[] = {2, 5, 5, 5, 10};
int n = sizeof(a) / sizeof(a[0]);
int i;
int j;
for (int t : {-1, 0, 2, 3, 5, 6, 10, 11}) {
// testing iterative implementation
i = dsac::array::lower_bound_iterative(a, n, t);
j = std_lower_bound(a, n, t);
bool ok1 = (i==j);
assert(ok1);
i = dsac::array::lower_bound_iterative(a, n, t);
j = std_lower_bound(a, n, t);
bool ok2 = (i==j);
assert(ok2);
i = dsac::array::lower_bound_iterative(a, n, t);
j = std_lower_bound(a, n, t);
bool ok3 = (i==j);
assert(ok3);
i = dsac::array::upper_bound_iterative(a, n, t);
j = std_upper_bound(a, n, t);
bool ok4 = (i==j);
assert(ok4);
// test recursive implementations
i = dsac::array::lower_bound(a, n, t);
j = std_lower_bound(a, n, t);
bool ok5 = (i==j);
assert(ok5);
i = dsac::array::upper_bound(a, n, t);
j = std_upper_bound(a, n, t);
bool ok6 = (i==j);
assert(ok6);
// test frequency calculation
i = dsac::array::frequency(a, n, t);
j = std_frequency(a, n, t);
bool ok7 = (i==j);
assert(ok7);
i = dsac::array::frequency_iterative(a, n, t);
j = std_frequency(a, n, t);
bool ok8 = (i==j);
assert(ok8);
std::cout << "Target " << t << ": ";
std::cout << "LB=" << dsac::array::lower_bound(a, n, t) << ", ";
std::cout << "UB=" << dsac::array::upper_bound(a, n, t) << ", ";
std::cout << "Freq=" << dsac::array::frequency(a, n, t) << std::endl;
}
std::cout << "** All tests passed **\n";
return 0;
}
*/
//for array {2, 5, 5, 5, 10};
/*
Target -1: LB=0, UB=0, Freq=0
Target 0: LB=0, UB=0, Freq=0
Target 2: LB=0, UB=1, Freq=1
Target 3: LB=1, UB=1, Freq=0
Target 5: LB=1, UB=4, Freq=3
Target 6: LB=4, UB=4, Freq=0
Target 10: LB=4, UB=5, Freq=1
Target 11: LB=5, UB=5, Freq=0
All tests passed!
*/
