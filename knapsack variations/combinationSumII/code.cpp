#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int ind,vector<vector<int>>& res,vector<int>& temp,vector<int> candidates,int target,int n){
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            //To handle duplicates
            if(i>ind and candidates[i]==candidates[i-1])
                continue;
            //No need of solving further as the element is greater than target and next elements would also be greater than target since the array is sorted
            if(candidates[i]>target)
                break;
            temp.push_back(candidates[i]);
            solve(i+1,res,temp,candidates,target-candidates[i],n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0,res,temp,candidates,target,n);
        return res;
    }
};
class Solution {
public:
    void solve(int ind,vector<vector<int>>& res,vector<int>& temp,vector<int> candidates,int target,int n,map<vector<int>,bool>& mp){
        if(target==0){
            if(mp.find(temp)==mp.end())
            {
                res.push_back(temp);
                mp[temp]=true;
            }
            return;
        }
        if(ind==n or target<0)
            return;
        temp.push_back(candidates[ind]);
        solve(ind+1,res,temp,candidates,target-candidates[ind],n,mp);
        temp.pop_back();
        //To handle duplicates
        while(ind<n-1 and candidates[ind]==candidates[ind+1])
            ind++;
        solve(ind+1,res,temp,candidates,target,n,mp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        map<vector<int>,bool> mp;
        solve(0,res,temp,candidates,target,n,mp);
        return res;
    }
};