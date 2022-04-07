#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int ind,vector<int>& candidates,vector<vector<int>>& res,vector<int> temp,int target,int n){
        if(ind==n or target<0)
            return;
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        solve(ind+1,candidates,res,temp,target,n);
        temp.push_back(candidates[ind]);
        solve(ind,candidates,res,temp,target-candidates[ind],n);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        int n = candidates.size();
        solve(0,candidates,res,temp,target,n);
        return res;
    }
};