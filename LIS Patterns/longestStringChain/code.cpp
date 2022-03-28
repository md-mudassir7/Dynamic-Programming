#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool comp(string& a,string& b)
    {
        return a.size()<b.size();
    }
    bool check(string &s1, string &s2)
    {
        if(s1.size() != s2.size()-1)
            return false;
        int i=0,j=0,cnt=0;
        while(i<s1.size() and j < s2.size())
        {
        
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                cnt++;
                if(cnt==2)
                    return false;
                else
                    j++;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);    
        int ans = 1;
        int n = words.size();
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(check(words[j],words[i]))
                    dp[i]=max(dp[i],dp[j]+1);
            }
            ans = max(ans,dp[i]);
        }
        cout<<endl;
        return ans;
    }
};