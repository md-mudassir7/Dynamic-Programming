#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int sum1 = 0,sum2 = 0;
        for(auto x : s1)
            sum1+=x;
        for(auto x : s2)
            sum2+=x;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++){
                if(i==0 or j==0)
                    dp[i][j]= 0 ;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+s1[i-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return sum1 + sum2 - 2*dp[n][m];
    }
};