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

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int first_buy=INT_MIN,second_buy=INT_MIN;
        int first_sell=0, second_sell = 0;
        for(int i=0;i<n;i++){
            //Since we do not have anything with us we are investing prices[i] for first_buy hence the negative sign
            first_buy = max(first_buy,-1*prices[i]);
            //We have bought the first stock and now we are selling it hence we are gaining amount of value = prices[i]
            first_sell = max(first_sell,first_buy+prices[i]);
            //We have the profit of first transaction with us now i.e stored in the variable first_buy and now we are investing prices[i] for second_buy hence the negative sign
            second_buy = max(second_buy,first_sell-prices[i]);
            //We have bought the second stock and now we are selling it hence we are gaining amount of value = prices[i]
            second_sell = max(second_sell,second_buy+prices[i]);

            //We are maximimizing all of the above values to get the maximu  profit of those 2 transactions
            //At the end the profit we gain will be stored in second_sell variable
        }
        return second_sell;
    }
};