#include<bits/stdc++.h>
using namespace std;
class Solution {
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
class Solution {
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