#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        int dp[m+1][n+1];
        int largest = 0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(arr[i-1][j-1]=='1')
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                else
                    dp[i][j] = 0;
                largest = max(largest,dp[i][j]);
            }
        }
        return largest*largest;
    }
};