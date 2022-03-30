#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        int start,len;
        
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0)
                    dp[i][j] = 1;
                else if(gap==1){
                    if(s[i]==s[j])
                        dp[i][j] = 1;  
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j] = 1;          
                }
                if(dp[i][j]){
                    start = i;
                    len = j-i+1;
                }
            }
        }
        return s.substr(start,len);
    }
};