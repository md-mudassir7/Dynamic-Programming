#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fun(int ind,int canBuy,vector<int>& prices,vector<vector<int>>& dp,int n){
        if(ind>=n)
            return 0;
        if(dp[ind][canBuy]!=-1)
            return dp[ind][canBuy];
        int profit = 0;
        if(canBuy){
            //denotes that we can buy

            //If we buy -> -prices[ind]+fun(ind+1,0,prices,n)

            //If we do not buy -> fun(ind+1,1,prices,n)
            //Understand how 0,1 is being updated
            profit = max(-prices[ind]+fun(ind+1,0,prices,dp,n),fun(ind+1,1,prices,dp,n));
        }
        else
        {
            //denotes that we should sell

            //If we sell -> +prices[ind]+fun(ind+2,1,prices,n) we move to index+2 since we should skip the cooldown days

            //If we do not sell -> fun(ind+1,0,prices,n)
            
            profit = max(prices[ind]+fun(ind+2,1,prices,dp,n),fun(ind+1,0,prices,dp,n));
        }
        return dp[ind][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,1,prices,dp,n);
    }
};