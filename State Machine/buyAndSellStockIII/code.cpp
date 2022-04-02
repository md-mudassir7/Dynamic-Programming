#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fun(int ind,int canBuy,int noOfTransactionRemaining,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(noOfTransactionRemaining==0)
            return 0;
        int n = prices.size();
        if(ind==n)
            return 0;
        if(dp[ind][canBuy][noOfTransactionRemaining]!=-1)
            return dp[ind][canBuy][noOfTransactionRemaining];
        int profit = 0;
        if(canBuy){
            profit = max(-prices[ind]+fun(ind+1,0,noOfTransactionRemaining,prices,dp),fun(ind+1,1,noOfTransactionRemaining,prices,dp));
        }
        else
            profit = max(prices[ind]+fun(ind+1,1,noOfTransactionRemaining-1,prices,dp),fun(ind+1,0,noOfTransactionRemaining,prices,dp));
        return dp[ind][canBuy][noOfTransactionRemaining] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,
                                      vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(0,1,2,prices,dp);
    }
};