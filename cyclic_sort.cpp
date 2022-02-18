#include <iostream>
#include <vector>

using namespace std; 

void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i]; 
    arr[i] = arr[j]; 
    arr[j] = temp; 
}

void cyclicSort(vector<int> &nums) {
    int i = 0; 
    while (i < nums.size()) {
        int j = nums[i] - 1; 
        if (nums[i] != nums[j]) {
            swap(nums, i, j);
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> arr = {3,1,5,4,2}; 
    cyclicSort(arr);
    for (auto num : arr) {
        cout << num << " "; 
    }
}