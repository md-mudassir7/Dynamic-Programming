#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int dp[n];
        int ans = 1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(arr[i][0]>arr[j][0] and arr[i][1]>arr[j][1] and dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};