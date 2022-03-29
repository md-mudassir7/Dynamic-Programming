1st Approach

    1.This is similar to LCS

    2.Find the LCS between the 2 strings

    3.The answer will be m+n-2*(length of LCS) where n = length of word1, m = length of word2


2nd Approach

    1.Base cases

        *Both strings are empty: 0
        
        *One string is empty. We have to delete all the character in other string to make it empty. So min. no of moves has to be equal to the length of the non-empty string.

    2. Definition of problem.

        *If both characters are same. We dont have to delete it, so the moves will be equal to subproblem with state(i -1, j - 1)
        
        *If both characters are not the same. We can delete character from either string. So the min no of moves has to be minimum between dp[i][j - 1] and dp[i - 1][j].