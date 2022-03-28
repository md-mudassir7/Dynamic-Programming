#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        int dp[n];
        int count[n];
        int temp = 1;
        for(int i=0;i<n;i++){
            dp[i]=1;
            count[i]=1;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] and dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(dp[j]+1==dp[i])
                    count[i]+=count[j];
            }
            temp = max(temp,dp[i]);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==temp)
                cnt+=count[i];
        }
        return cnt;
    }
};