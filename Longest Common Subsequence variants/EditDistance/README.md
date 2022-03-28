Approach

    1.We create a dp matrix of size nxm where n is size of word1 and m is size of word2

    2.At any point (i,j) dp[i][j] denotes the minimum edit distance value for strings word1 till index i and word2 till index j

    3.We have 2 choices at any point i.e if the current characters of both strings are same and the characters are not same

    4.If the characters are same then we dont have to perform anythin we just store the answer of dp[i-1][j-1] since no edit is required

    5.If they are not same then dp[i][j] is the minimum of 3 values(insert,delete and replace) 

    6.Insertion is dp[i][j-1] , deletion is dp[i-1][j] and replace is dp[i-1][j-1] clearly explained in the test case below


Dry Run

    1.String a = "ABC" , String b = "BCD"
    
    2.We have three operations to make string a to b.
    
    3.And we have to choose/return min cost operations.
    
    4.If we look at string a's and b's first character A and B then we can perform 3 operations.

    5.If we perform insert operation, then pointer from b string will get incremented by 1,
    i.e. a = "AABC"
    b = "CD"
    here pointer at string a remains the same but pointer at string b will be +1 as it matches the new inserted character for sure.
    The operation cost -> dp[i][j-1] + 1

    6.If we perform delete operation, then pointer from a string will get decremented by 1,
    i.e a = "BC"
    b = "BCD"
    here pointer at string b remains the same but pointer at string a will be -1 as we remove/deleted a character.
    The operation cost -> dp[i-1][j] + 1

    7.If we perform replace operation, then pointer from both a and b string will get incremented by 1.
    a = "BC"
    b = "CD"
    here pointer at string a and b will be -1 as we replaced the character.
    The operation cost -> dp[i-1][j-1] + 1

    8.Above all operation costs us +1 operation each time we perform the operation.
    
    9.After each computation of smaller problems i.e. for smaller lengths of both strings, we will store the result in dp table at the dp[a.length()][b.length()].


