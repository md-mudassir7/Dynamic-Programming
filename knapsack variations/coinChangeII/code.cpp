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
            int pick = solve(ind,amount-coins[ind],coins,n);
            int skip = solve(ind+1,amount,coins,n);
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
        for(int i=0;i<=amount;i++)
            dp[0][i] = 0;
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    int pick = dp[i][j-coins[i-1]];
                    int skip = dp[i-1][j];
                    dp[i][j] =  pick+skip;
                }
                else
                    dp[i][j] = dp[i-1][j];
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