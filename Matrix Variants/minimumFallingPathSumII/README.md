Problem [link](https://leetcode.com/problems/minimum-falling-path-sum-ii/)

Approach

    1.Similat to minimumFallingPathSumI but here instead of 3 directions we can have the falling sum from the whole previous row

    2.Hence we run a for loop for all the previous row elements and find out the minimum of that row and store it at the current block(i,j)

