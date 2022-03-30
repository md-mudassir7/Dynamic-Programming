#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        int res = 0;
        memset(dp,0,sizeof(dp));
        for(int g = 0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)
                    dp[i][j] = 1;
                else if(g==1){
                    if(s[i]==s[j])
                        dp[i][j] = 1;
                }
                else
                {
                    if(s[i]==s[j] and dp[i+1][j-1])
                        dp[i][j] = 1;
                }
                if(dp[i][j])
                    res++;
            }
        }
        return res;
    }
};