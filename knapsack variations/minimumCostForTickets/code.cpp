#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind,vector<int>& days, vector<int>& costs,vector<int>& dp){
        if(ind>=days.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int choice1 = costs[0]+solve(ind+1,days,costs,dp);
        int k = ind;
        while(k<days.size() and days[k]<days[ind]+7)
            k++;
        int choice2 = costs[1]+solve(k,days,costs,dp);
        while(k<days.size() and days[k]<days[ind]+30)
            k++;
        int choice3 = costs[2]+solve(k,days,costs,dp);
        return dp[ind] = min(min(choice1,choice2),choice3);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,-1);
        return solve(0,days,costs,dp);
    }
};
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int last7 = 0;
        int last30 = 0;
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            while(days[i-1]-days[last7]>=7)
                last7++;
            while(days[i-1]-days[last30]>=30)
                last30++;
            dp[i] = min({dp[i-1] + costs[0], dp[last7] + costs[1], dp[last30] + costs[2]});
        }
        return dp[n];
    }
};