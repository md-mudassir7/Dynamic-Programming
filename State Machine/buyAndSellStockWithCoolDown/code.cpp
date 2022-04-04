#include<bits/stdc++.h>
using namespace std;
class Solution1 {
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

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n+1][0]=0;
        dp[n+1][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    //denotes that we can buy

                    //If we buy -> -prices[ind]+dp[ind+1][0]

                    //If we do not buy -> dp[ind+1][1]
                    //Understand how 0,1 is being updated
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]); 
                }
                else
                {
                    //denotes that we should sell

                    //If we sell -> prices[ind]+dp[ind+2][1]

                    //If we do not sell -> dp[i+1][0]
            
                    profit = max(prices[i]+dp[i+2][1],dp[i+1][0]); 
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};