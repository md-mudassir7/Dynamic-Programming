#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int dp[n];
        int ans = 1;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};