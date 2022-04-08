#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                //If the element is last element of row
                //Hence the falling path sum for this element will be the sum coming from its diagonally previous element([i-1][j-1])
                if(j==triangle[i].size()-1)
                    triangle[i][j]+= triangle[i-1][j-1]; 
                //Else it is the the minimum falling sum coming from its upper value and diagonally previous value
                else
                    triangle[i][j] = triangle[i][j] + min(triangle[i>0?i-1:0][j],triangle[i>0?i-1:0][j>0?j-1:0]);
            }
        }
        int mini = triangle[n-1][0];
        for(int i=1;i<triangle[n-1].size();i++)
            mini = min(mini,triangle[n-1][i]);
        return mini;
    } 
};