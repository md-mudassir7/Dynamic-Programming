#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind,vector<int>& coins,int amount,int n){
        if(amount==0)
            return 0;
        if(ind==n or amount<0)
            return 100000;
        if(coins[ind]<=amount){
            //We can pick the coin at index ind i.e coins[ind]

            //If we pick
            int pick = 1+solve(ind,coins,amount-coins[ind],n);
            //If we do not pick
            int skip = solve(ind+1,coins,amount,n);
            //Take the max of above 2 value and return
            return min(pick,skip);
        }
        else
        {
            //This portion says we cannot pick hence we have to move onto the next index
            return solve(ind+1,coins,amount,n);;
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(0,coins,amount,n);
        return ans==100000?-1:ans;
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        //If we have 0 coins then we require Infinite coins to make up the amount hence the below code
        for(int i=0;i<=m;i++)
            dp[0][i] = INT_MAX-1;
        //If the amount is 0 then we require 0 coins to make up that amount
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                if(coins[i-1]<=j){
                    //Max of pick and skip
                    dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
                else
                {
                    //We have to Skip if we canot pick
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m]==INT_MAX-1?-1:dp[n][m];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        vector<int> prev(m+1,INT_MAX-1);
        vector<int> curr(m+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                if(coins[i-1]<=j){
                    //Max of pick and skip
                    curr[j] = min(1+curr[j-coins[i-1]],prev[j]);
                }
                else
                {
                    //We have to Skip if we canot pick
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return curr[m]==INT_MAX-1?-1:curr[m];
    }
};