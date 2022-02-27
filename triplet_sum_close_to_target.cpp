#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int searchTriplet(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int min_diff = numeric_limits<int>::max(); 

    for (int i=0; i<arr.size()-2; i++) {
        int left = i+1, right = arr.size()-1; 

        while (left < right) {
            int diff = target - arr[i] - arr[left] - arr[right]; 

            if (diff == 0) {
                return target; 
            }

            if (abs(diff) < abs(min_diff)) {
                min_diff = diff; 
            }

            if (diff > 0) {
                left++; 
            } else {
                right--; 
            }
        }
    }

    return target - min_diff; 
}

int main() {
    vector<int> vec = {-3, -1, 1, 2};
    cout << searchTriplet(vec, 1) << endl; 
}