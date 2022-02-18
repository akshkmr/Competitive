#include <iostream>
#include <vector>
using namespace std; 

int main() {
    int n; 
    cin >> n; 
    vector<int> v(n); 
    for (int i = 0; i<n; i++) {
        cin >> v[i]; 
    }

    int to_find; 
    cin >> to_find; 

    int l = 0, h = n-1; 

    while ((h-l) > 1) {
        int mid = (l + h) / 2; 

        if (v[mid] < to_find) {
           l = mid + 1;  
        } else {
           h = mid;
        }
    }

    if (v[l] == to_find) 
        cout << l << endl; 
    else if (v[h] == to_find)
        cout << h << endl; 
    else 
        cout << "Not Found"; 
}