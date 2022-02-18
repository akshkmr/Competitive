#include <iostream>
#include <vector>

using namespace std; 

int knapsackRecursive(vector<int> &profits, vector<int> &weights, int capacity, int currentIndex) {

    if (capacity <= 0 || currentIndex >= profits.size())
        return 0;
    
    int profit1 = 0; 
    if(weights[currentIndex] <= capacity) {
        profit1 =
            profits[currentIndex] +
            knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex);
    }

    int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex+1);

    return max(profit1, profit2);
}

int solveKnapsack(vector<int> &profits, vector<int> &weights, int capacity) {
    return knapsackRecursive(profits, weights, capacity, 0);
}

int main() {
    vector<int> profits = {15, 50, 60, 90}; 
    vector<int> weights = {1, 3, 4, 5}; 

    int maxProfit = solveKnapsack(profits, weights, 6); 
    cout << maxProfit << endl; 
}