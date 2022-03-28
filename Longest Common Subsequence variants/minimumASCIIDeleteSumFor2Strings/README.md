Approach

    1.This question is just a variation of lcs as there we need to find out the length,here we need to find out sum of their ascii values, just a slight change is there i.e we need to add the ascii value of the character to dp[i][j] when s1[i-1]==s2[j-1]
    
    2.At last we have our ans which is basically the sum of ascii value of the longest common subsequence. 

    3.Hence the result will be sum1(of chars of string s1) + sum2(of chars of string s2) - 2*dp[n][m] which stores the sum of the LCS between 2 strings