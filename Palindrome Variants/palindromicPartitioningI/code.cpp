#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void fun(string& s,int ind,int n,vector<vector<string>>& ans,vector<string>& temp){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                fun(s,i+1,n,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        fun(s,0,s.size(),ans,temp);
        return ans;
    }
};