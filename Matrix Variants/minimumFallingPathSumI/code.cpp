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
                dp[i][j] = matrix[i-1][j-1]+min(min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1]);
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
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      for (auto i = 1; i < matrix.size(); ++i)
        for (auto j = 0; j < matrix.size(); ++j)
          matrix[i][j] += min({ matrix[i-1][j], matrix[i-1][max(0,j-1)], matrix[i-1][min((int)matrix.size()-1,j+1)] });
      return *min_element(begin(matrix[matrix.size() - 1]), end(matrix[matrix.size() - 1]));
    }
};