#include <iostream>
#include <vector>

using namespace std; 

const int N = 1e3; 
bool visited[N]; 
vector<int> adj[N]; 

void dfs(int node) {
    visited[node] = true;
    cout << node << " "; 

    for(auto num : adj[node]) {
        if (!visited[num])
            dfs(num);
    }
}

int main() {
    int vertices, edges; 
    cin >> vertices >> edges; 

    int x,y; 
    for (int i=0; i<edges; i++) {
        cin >> x >> y;
        adj[x].push_back(y); 
        adj[y].push_back(x); 
    } 

    dfs(1); 
}