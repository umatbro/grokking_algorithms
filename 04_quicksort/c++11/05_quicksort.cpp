#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;
using std::printf;

template <typename T>
std::vector<T> quicksort(const std::vector<T>& arr) {
    // base case, arrays with 0 or 1 element are already "sorted"
    if (arr.size() < 2) 
        return arr;
    
    // recursive case
    const T* pivot = &arr.front() + arr.size() / 2 - 1; // set the pivot somewhere in the middle
    std::vector<T> less;  // vector to store all the elements less than the pivot
    std::vector<T> greater;  // vector to store all the elements greater than the pivot

    for (const T* item = &arr.front(); item <= &arr.back(); item++) {
        if (item == pivot) continue; // skip pivot element
        if (*item <= *pivot) less.push_back(*item);
        else greater.push_back(*item);
    }
    
    std::vector<T> sorted_less = quicksort(less);
    std::vector<T> sorted_greater = quicksort(greater);
    // concatenate less part, pivot and greater part
    sorted_less.push_back(*pivot);
    sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());
    
    return sorted_less;
}

template <typename T>
void __quicksort_inplace(T* begin, T* end) {
    T* left = begin;
    T* right = end;

    int arr_length = end - begin;
    printf("ARRLEN %d\n", arr_length);

    if (arr_length <= 1) 
        return;
    
    // get random pivot
    T pivot_val =  *(begin + std::rand() % (arr_length));
    
    while (left <= right) {
        while (*left < pivot_val) {
            left++;
        }
        while (*right > pivot_val) {
            right--;
        }
        std::swap(*left, *right);
                
        left++;
        right--;   
    }

    __quicksort_inplace(begin, left-1);
    __quicksort_inplace(right+1, end);
}

template <typename T>
void quicksort_inplace(std::vector<T>& arr) {
    T* start = &arr.front();
    T* end = &arr.back();

    __quicksort_inplace(start, end);
}

int main() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    
    // std::vector<int> arr = {1, 2, 7, 8, 3, 4, 10};
    std::vector<int> arr = {69, 60, 38, 82, 99, 15, 8, 94, 30, 42, 35, 40, 63, 1, 49, 66, 93, 83, 20, 32, 87, 6, 78, 17, 2, 61, 91, 25, 7, 4, 97, 31, 23, 67, 95, 47, 55, 92, 37, 59, 73, 81, 74, 41, 39};
    // std::vector<int> sorted = quicksort(arr);
    // for (int num : sorted) {
    //     cout << num << " ";
    // }
    // cout << endl;
    quicksort_inplace(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    int prev_value = 0;
    for (int i=0; i < arr.size(); i++ ) {
        if (arr[i] < prev_value) {
            printf("ERROR: %d\n", arr[i]);
        }
        prev_value = arr[i];
    }
}