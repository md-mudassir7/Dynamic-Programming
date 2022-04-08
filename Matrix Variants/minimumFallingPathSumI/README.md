Problem [link](https://leetcode.com/problems/minimum-falling-path-sum/)

Approach

    1.The problem is similar to maximal square

    2.We create a dp array of size (n+1)x(n+1) 

    3.At any index in the matrix the value dp[i][j] denotes the minimum falling path sum from top to that point (i,j)

    4.dp[i][j] is the minimum of 3 values(top diagonally left,top diagonally right and the top value)

    5.At the end we return the minimum value stored in the last row of dp matrix


Approach2

    1.This is a space optimised solution for the above dp code

    2.Instead of creating the dp matrix we Modify the existing matrix itself and return the minimum value stored in the last row of the matrix

    3.The code gives better understanding