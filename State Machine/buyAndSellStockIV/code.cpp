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
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,
                                      vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(0,1,k,prices,dp);
    }
};

class Solution2 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=1 || k==0)
            return 0;
        int res=0;
        if(k>=n/2)
        {
            for(int i=0;i<n-1;i++)
            {
                if(prices[i+1]>prices[i])
                    res+=prices[i+1]-prices[i];
            }
            return res;
        }
        
        
        int buy[k],sell[k];
        for(int i=0;i<k;i++)
        {
            buy[i]=INT_MIN;
            sell[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                //If this is the first transaction then we are paying amount of worth prices[i] to buy it else we have the profit of previous 
                //transaction stored in sell[j-1] hence we subtract the profit with prices[i] to store the left out money in buy[i]
                //Hence the condition j==0 
                buy[j]=max(buy[j],j==0?0-prices[i]:sell[j-1]-prices[i]);
                //If we are selling the stock then we are gaining the amount stored in pices[i] and the money left with us after buying a stock 
                //Which will be stored in buy[j] hence we add buy[j] and prices[i]
                sell[j]=max(sell[j],buy[j]+prices[i]);
            }
        }
        //The value stored in the last sell is our profit hence we just return that
        return sell[k-1];
    }
};