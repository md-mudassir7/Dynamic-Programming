#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    int fun(int ind,int canBuy,vector<int>& prices,int n){
        if(ind==n){
            return 0;
        }
        int profit =  0;
        if(canBuy){
            //denotes that we can buy

            //If we buy -> -prices[ind]+fun(ind+1,0,prices,n)

            //If we do not buy -> fun(ind+1,1,prices,n)
            //Understand how 0,1 is being updated
            profit = max(-prices[ind]+fun(ind+1,0,prices,n),fun(ind+1,1,prices,n));
        }
        else
        {
            //denotes that we should sell

            //If we sell -> +prices[ind]+fun(ind+1,1,prices,n)

            //If we do not sell -> fun(ind+1,0,prices,n)
            
            profit = max(+prices[ind]+fun(ind+1,1,prices,n),fun(ind+1,0,prices,n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return fun(0,1,prices,prices.size());
    }
};
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    profit = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]<prices[i+1])
                res+=prices[i+1]-prices[i];
        }
        return res;
    }
};