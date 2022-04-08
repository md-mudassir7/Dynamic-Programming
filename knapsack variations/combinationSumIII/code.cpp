#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int ind,vector<vector<int>>& res,vector<int>& temp,int k,int n){
        if(n<0)
            return; // Return ; No need to check further as the required sum till now become greater than n 
        if(n==0 and temp.size()==k){ 
            res.push_back(temp); // Found the combination so just push that into res vector
            return;
        }
        for(int i=ind;i<=9;i++){
            temp.push_back(i); // includes the ith value
            solve(i+1,res,temp,k,n-i); // check values after that as each number should be used at most once
            temp.pop_back(); // pop_back the last value included as that combination doesn't make the sum
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(1,res,temp,k,n);
        return res;
    }
};