//std::lower_bound std::upper_bound
 #include <algorithm>
 #include "array/array_bounds.hpp"
 // Standard lower_bound function for testing (given for testing)
 int std_lower_bound(const int* arr, int n, int target){
     auto it = std::lower_bound(arr, arr+n, target);
     int idx = it - arr; // convert iterator to index
     return idx;
 }

 // Standard upper_bound function for testing (given for testing)
 int std_upper_bound(const int* arr, int n, int target){
     auto it = std::upper_bound(arr, arr+n, target);
     int idx = it - arr; // convert iterator to index
     return idx;
 }

 // std_frequency function for testing 
 // using std_lower_bound and std_upper_bound (given for testing)
 int std_frequency(const int *arr, int n, int target) {
     auto lb = std::lower_bound(arr, arr+n, target);
     auto ub = std::upper_bound(arr, arr+n, target);
     return ub - lb;
 }

  namespace dsac::array
  {
     // Recursive versions
     int lower_bound(const int* arr, int n, int target)
     { 
        return lower_bound_recursive(arr, 0, n, target);
     }
     int upper_bound(const int* arr, int n, int target)
     {
        return upper_bound_recursive(arr, 0, n, target);
     }
     int frequency(const int *arr, int n, int target)
     {
        return upper_bound_recursive(arr, 0, n, target) - lower_bound_recursive(arr, 0, n, target);
     }
     // Recursive helper versions
     // you may create helper functions
int lower_bound_recursive(const int* arr, int low, int high, int target){

    if(low >= high){
        return low;      // end of search
    }
    int mid{low + (high-low) / 2};
    if(arr[mid] >= target)
        return lower_bound_recursive(arr, low, mid, target);
    else
        return lower_bound_recursive(arr, mid+1, high, target);
}
int upper_bound_recursive(const int* arr, int low, int high, int target)
{
    if(low >= high){
        return low;     // end of search
    }
    int mid{low + (high-low) / 2};
    if(arr[mid] > target)
        return upper_bound_recursive(arr, low, mid, target);
    else
        return upper_bound_recursive(arr, mid+1, high, target);
}

     // Iterative versions
     int lower_bound_iterative(const int* arr, int n, int target)
     {
        int low{0};
        int high{n-1};
        int index{n};

        while(low <= high){
            int mid{low + (high-low) / 2};
            if(arr[mid] >= target)
            {
                index = mid;          
                high = mid - 1;
            }
            else
                low = mid+1;
        }
        return index;
     }
     int upper_bound_iterative(const int* arr, int n, int target)
     {
        int low{0};
        int high{n-1};
        int index{n};

        while(low <= high){
            int mid{low + (high-low) / 2};
            if(arr[mid] > target)
            {
                index = mid;          
                high = mid - 1;
            }
            else
                low = mid+1;
        }
        return index;
     }

     int frequency_iterative(const int *arr, int n, int target)
     {
        return upper_bound_iterative(arr, n, target) - lower_bound_iterative(arr, n, target);
     }
 }