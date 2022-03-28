#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        int temp = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0)
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            temp = max(temp,dp[i]);
        }
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==temp and (ans.size()==0 or ans[ans.size()-1]%nums[i]==0))
            {
                ans.push_back(nums[i]);
                temp--;
            }
        }
        return ans;
    }
};