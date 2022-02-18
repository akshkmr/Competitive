#include <iostream>
#include <vector>
#include <set>

using namespace std; 

const int N = 1e5; 
const int inf = 1e9;

vector<pair<int,int>> graph[N]; 

void dijkstra(int source, int n) {
    vector<int> visited(N, 0); 
    vector<int> distance(N, inf); 

    set<pair<int, int>> st; 
    st.insert({0, source}); 

    distance[source] = 0; 

    while(st.size() > 0) {
        auto node = *st.begin(); 
        int v = node.second; 
        int dist = node.first; 

        st.erase(st.begin()); 
        if (visited[v]) continue; 

        visited[v] = 1; 

        for (auto child : graph[v]) {
            int child_v = child.first; 
            int wt = child.second; 

            if (distance[v] + wt < distance[child_v]) {
                distance[child_v] = distance[v] + wt; 
                st.insert({distance[child_v], child_v}); 
            }
        }
    }


    for (int i=1; i<n+1; i++) {
        cout << distance[i] << " "; 
    }
}

int main() {
    int n, m; 
    cin >> n >> m; 

    for (int i=0; i<m; i++) {
        int u,v,w;
        cin >> u >> v >> w; 
        graph[u].push_back({v,w}); 
        graph[v].push_back({u,w}); 
    }

    dijkstra(1, n); 
}