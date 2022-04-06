#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind,int amount,vector<int>& coins,int n){
        if(ind>=n){
            return 0;
        }
        if(amount==0)
            return 1;
        if(coins[ind]<=amount){
            //Indicates that We can pick the coin at index ind i.e coins[ind]

            //If we pick
            
            int pick = solve(ind,amount-coins[ind],coins,n);

            //If we do not pick
            int skip = solve(ind+1,amount,coins,n);

            //Return the summation of above 2 values
            return pick+skip;
        }
        else
            return solve(ind+1,amount,coins,n);
    }
    int change(int amount, vector<int>& coins) {
        return solve(0,amount,coins,coins.size());
    }
};
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n+1][amount+1];
        //If we have 0 coins then we require 0 coins to make up the amount hence the below code
        for(int i=0;i<=amount;i++)
            dp[0][i] = 0;
        //If the amount is 0 then we require 1 coins to make up that amount i.e the set []
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    //Sum of pick and skip
                    int pick = dp[i][j-coins[i-1]];
                    int skip = dp[i-1][j];
                    dp[i][j] =  pick+skip;
                }
                else
                {
                    //We have to Skip if we canot pick
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        prev[0]=1;
        curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    int pick = curr[j-coins[i-1]];
                    int skip = prev[j];
                    curr[j] =  pick+skip;
                }
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return curr[amount];
    }
};