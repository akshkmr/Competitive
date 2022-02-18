#include <iostream>
#include <vector> 

using namespace std; 

int countChangeRecursive(vector<int> &denominations, int total, int currentIndex) {
    if (total == 0) 
        return 1; 

    if (total < 0 || denominations.empty() || currentIndex >= denominations.size())
        return 0; 

    int sum1 = 0; 
    if (denominations[currentIndex] <= total) {
        sum1 = countChangeRecursive(denominations, total-denominations[currentIndex], currentIndex);
    }  

    int sum2 = countChangeRecursive(denominations, total, currentIndex+1);
    return sum1 + sum2;  
}

int countChange(vector<int> &denominations, int total) {
    return countChangeRecursive(denominations, total, 0);
}

int main() {
    vector<int> denominations = {1,2,3};
    cout << countChange(denominations, 5) << endl; 
}
