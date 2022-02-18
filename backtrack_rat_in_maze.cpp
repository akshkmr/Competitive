#include <iostream>
#include <vector>

using namespace std; 

bool isSafe(vector<vector<int>> &arr, int x, int y, int n){
    if (x<n && y<n && arr[x][y] == 1)
        return true; 
    return false; 
}

bool ratInMaze(vector<vector<int>> arr, int x, int y, int n, vector<vector<int>> &soln){
    if ((x==(n-1)) && (y==(n-1))) {
        soln[x][y] = 1; 
        return true; 
    }
    
    if (isSafe(arr, x, y, n)) {
       soln[x][y] = 1;
       if (ratInMaze(arr, x+1, y, n, soln)) {
           return true; 
       }
       if (ratInMaze(arr, x, y+1, n, soln)) {
           return true; 
       }
       soln[x][y] = 0; 
    }
    return false; 
}

int main() {
    int n; 
    cin >> n; 
    cout << endl; 
    vector<vector<int>> arr(n, vector<int>(n)); 
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j]; 
        }
    }

    vector<vector<int>> soln(n, vector<int>(n)); 

    if (ratInMaze(arr, 0, 0, n, soln)) {
        cout << endl; 
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << soln[i][j] << " "; 
            }
            cout << endl; 
        }
    }

    return 0; 
}