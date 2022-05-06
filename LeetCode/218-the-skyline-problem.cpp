#include <vector>
#include <queue>


// 1. Sort all appeared x coordinates and remove duplicates.
// 2. Iterate thought the coordinates from left to right. Add a pair<height, rightEdgeCoordinate> to priority_queue if we have already reached the left edge of this building. Then continuously pop the top element of the priority_queue if we have reached its right edge coordinate.
// 3. Now we've got the tallest building at the present coordinate at the top of priority_queue. Add it to answer if it's different from previous height.


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
    for (int i=0; i<m; i++) {
        while (j<buildings.size() && buildings[j][0]==co[i]) 
            pq.push(make_pair(buildings[j][2], buildings[j][1])), j++;
        while (!pq.empty() && pq.top().second<=co[i]) pq.pop();
        int nowH = pq.empty() ? 0 : pq.top().first;
        if (nowH != preH) {
            ans.push_back({co[i], nowH});
            preH=nowH;
        }
    }
    return ans;
}