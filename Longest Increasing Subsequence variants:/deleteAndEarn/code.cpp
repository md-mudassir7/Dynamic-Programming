#include<bits/stdc++.h>
using namespace std;
class Solution {
   public:
      int deleteAndEarn(vector < int > & nums) {
          int n = 10001;
          vector<int> freq(n,0);
          int dp[n];
          for (int num : nums){
              freq[num] += num;
          }
          dp[0] = 0;
          dp[1] = freq[1];
          for (int i = 2 ; i < n ; i++){
              dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]);    
          }
          return dp[n - 1];
      }
};