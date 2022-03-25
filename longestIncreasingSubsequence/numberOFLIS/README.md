Problem [link](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

Approach

    1.The problem is similar to LIS 

    2.Here we also declare a count array that will store the count of LIS uptil a given index

    3.Once we get the value of the LIS(i.e the length of longest increasing subsequence of an array)(temp) we traverse the dp array and check if the value at i i.e dp[i]==temp if yes we add the value stored at count[i] since it is the count of all those LIS's