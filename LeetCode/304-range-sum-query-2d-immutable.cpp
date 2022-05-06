#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std; 

class NumMatrix {
private:
    vector<vector<int>> prefixSum;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        prefixSum.resize(m,vector<int>(n));
        
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                prefixSum[i][j]=prefixSum[i][j - 1]+matrix[i][j];
            }
        }
        
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                prefixSum[i][j] += prefixSum[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=prefixSum[row2][col2];
        sum-=(col1>0)?prefixSum[row2][col1-1]:0;
        sum-=(row1>0)?prefixSum[row1-1][col2]:0;
        sum+=(row1>0 && col1>0)?prefixSum[row1-1][col1-1]:0;
        return sum;
    }
};