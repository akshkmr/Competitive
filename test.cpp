#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#include <queue>
#include <stack>


using namespace std; 

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    priority_queue<pair<int, int>> pq;
    vector<int> co;
    for (auto b:buildings) {
        co.push_back(b[0]);
        co.push_back(b[1]);
    }
    sort(co.begin(), co.end());
    int m = unique(co.begin(), co.end()) - co.begin();
    int j = 0, preH = 0;
    vector<vector<int>> ans;

    for (auto num : co)
        cout << num << endl; 

    // for (int i=0; i<m; i++) {
    //     while (j<buildings.size() && buildings[j][0]==co[i]) 
    //         pq.push(make_pair(buildings[j][2], buildings[j][1])), j++;
    //     while (!pq.empty() && pq.top().second<=co[i]) pq.pop();
    //     int nowH = pq.empty() ? 0 : pq.top().first;
    //     if (nowH != preH) {
    //         ans.push_back({co[i], nowH});
    //         preH=nowH;
    //     }
    // }
    return ans;
}

int main() {
    string s = "Akshay";
    vector<vector<int>> co = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<int> primes = {8, 6, 1, 9} ;

    primes.resize(3); 

    primes.erase(primes.begin()); 

    for (auto num : primes) 
        cout << num << endl; 
}