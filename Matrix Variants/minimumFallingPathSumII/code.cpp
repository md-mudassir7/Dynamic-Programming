#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            dp[0][i] = INT_MAX;
            dp[i][0] = INT_MAX;
        }
        for(int i=1;i<=n;i++){
            dp[1][i] = matrix[0][i-1];
        }
        
        for(int i=2;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dp[i][j] = matrix[i-1][j-1];
                int mini = INT_MAX;
                for(int k = 1;k<=n;k++){
                    if(k!=j){
                        mini = min(mini,dp[i-1][k]);
                    }
                }
                dp[i][j]+=mini;
            }
        }
        int mini = dp[n][1];
        for(int i=2;i<=n;i++)
        {
            mini = min(mini,dp[n][i]);
        }
        return mini;
    }
};