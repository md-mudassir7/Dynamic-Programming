Approach

    1.The solution for this problem is similar to LCS where dp[i][j] denotes the number of distinct subsequences between string s[:i] and t[:j]

    2.At any point we have 2 choices to make first is when characters at s[i] and t[j] are same and one case when they are not

    3.When the chars are same then dp[i][j] is the sum of 2 values(one is when we just move to i-1,j-1 since the characters are matching and one is when we just move to i-1,j to check if other subsequences of s match with t)

    4.If the chars are not same then its just i-1,j
    
    5.Note here that we are not changing j pointer because we know that all subsequences of s must exactly match with t 

Click [here](https://www.youtube.com/watch?v=-RDzMJ33nx8) for better understanding