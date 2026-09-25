//std::lower_bound std::upper_bound
 #include <algorithm>
 ​
 // Standard lower_bound function for testing (given for testing)
 int std_lower_bound(const int* arr, int n, int target){
     auto it = std::lower_bound(arr, arr+n, target);
     int idx = it - arr; // convert iterator to index
     return idx;
 }
 ​
 // Standard upper_bound function for testing (given for testing)
 int std_upper_bound(const int* arr, int n, int target){
     auto it = std::upper_bound(arr, arr+n, target);
     int idx = it - arr; // convert iterator to index
     return idx;
 }
 ​
 // std_frequency function for testing 
 // using std_lower_bound and std_upper_bound (given for testing)
 int std_frequency(const int *arr, int n, int target) {
     auto lb = std::lower_bound(arr, arr+n, target);
     auto ub = std::upper_bound(arr, arr+n, target);
     return ub - lb;
 }

  namespace dsac::array{
     // Recursive versions
     int lower_bound(const int* arr, int n, int target)
     { 
        return lower_bound_recursive(arr, 0, n, target);
     }
     int upper_bound(const int* arr, int n, int target);
     int frequency(const int *arr, int n, int target);
 ​
     // Recursive helper versions
     // you may create helper functions
int lower_bound_recursive(const int* arr, int low, int high, int target){
   if(low > high)
   {
    return n;
   }
   else{
    int mid{high - (high-low) / 2};
    if(arr[mid] >= target)
        return lower_bound_recursive(arr, low, mid-1);
    else 
        return lower_bound_recursive(arr, mid+1, high)
     }
}
int upper_bound_recursive(const int* arr, int low, int high, int target);

 ​
     // Iterative versions
     int lower_bound_iterative(const int* arr, int n, int target);
     int upper_bound_iterative(const int* arr, int n, int target);
     int frequency_iterative(const int *arr, int n, int target);
 }