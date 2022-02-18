#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

const int N = 1e3; 
bool visited[N]; 
vector<int> adj[N]; 

void bfs(int node) {
    queue<int> queue; 
    queue.push(node); 

    visited[node] = 1; 

    while(!queue.empty()){
        int front = queue.front(); 
        queue.pop();
        cout << front << " "; 

        for (auto num : adj[front]) {
            if (!visited[num]) {
                visited[num] = 1; 
                queue.push(num); 
            }
        }
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

    bfs(1); 
}