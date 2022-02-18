#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std; 

vector<int> topologicalSort(int vertices, vector<vector<int>> edges) {
    vector<int> sortedOrder; 
    if (vertices <= 0) {
        return sortedOrder; 
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree; 
    unordered_map<int, vector<int>> graph; 
    for (int i=0; i<vertices; i++) {
        inDegree[i] = 0; 
        graph[i] = vector<int>(); 
    }

    // b. Build the Graph
    for (int i=0; i<edges.size(); i++) {
        int parent = edges[i][0], child = edges[i][1]; 
        graph[parent].push_back(child);
        inDegree[child]++; 
    }

    // c. Find all the sources, all the vertices with 0 in-degree
    queue<int> sources; 
    for (auto entry : inDegree) {
        if (entry.second == 0) {
            sources.push(entry.first); 
        }
    }

    while(!sources.empty()) {
        int vertex = sources.front(); 
        sources.pop(); 
        sortedOrder.push_back(vertex); 
        vector<int> children =
                        graph[vertex]; 
        for (auto child : children) {
            inDegree[child]--; 
            if(inDegree[child] == 0) {
                sources.push(child);
            }
        }
    }

    if (sortedOrder.size() != vertices)
        return vector<int>(); 

    return sortedOrder; 
}

int main() {
    vector<int> result = 
        topologicalSort(4, {{3,2}, {3,0}, {2,1}, {2,1}}); 

    for (auto num : result) {
        cout << num << " "; 
    }

}