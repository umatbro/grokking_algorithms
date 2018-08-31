#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template<typename T>
int binary_search(const std::vector<T>& list, const int& item) {
    int low = 0;
    int high = list.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        T guess = list[mid];

        if (guess == item) {
            return mid;
        }

        if (guess > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}


int main() {
    std::vector<int> my_list = {1, 3, 5, 7, 9};
    cout << "Binary search for number 3: " << binary_search(my_list, 3) << endl;
    cout << "Binary search for number 4: " << binary_search(my_list, 4) << endl;

    return 0;
}
