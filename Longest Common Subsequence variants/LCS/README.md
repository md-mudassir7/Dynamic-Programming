Approach(class Solution1)

    1.Create a mxn matrix named dp at any point (i,j) dp[i][j] denotes the LCS of string s1 till index i and string s2 till index j 
    
    2.if the characters of both strings at i and j are the same then dp[i][j] = 1+ dp[i-1][j-1]

    3.If s1[i] != s2[j] , then we will pick the most optimal value either UP-VALUE dp[i - 1][j]  or  LEFT VALUE , dp[i][j - 1]
    Now why we picked max( LEFT , UP ) when text1[i] != text2[j] , because we consider our either string to be one length shorter to get the max len subsequence upto (i , j) which is nothing but we are taking max of lengths possible after removing last char from each string


Approach(class Solution2)

    1.This is a space optimised solution of the above dp approach

    2.We use 2 arrays prev and curr to calculate the LCS 