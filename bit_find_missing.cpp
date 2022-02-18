#include <iostream>
#include <vector>

using namespace std; 

int findMissingNumber(vector<int> arr) {
    int n = arr.size() + 1; 

    int x1 = 1;
    for (int i=2; i<=n; i++)
        x1 = x1 ^ i; 

    int x2 = arr[0];
    for (int i=1; i<arr.size(); i++)
        x2 = x2 ^ arr[i];

    return x1 ^ x2; 
}

int main() {
    vector<int> v1 = {1, 5, 2, 6, 4}; 
    cout << findMissingNumber(v1); 
}