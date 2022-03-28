Approach

    1.First of all, we will store the frequency of each number in an array of length 10000 (because nums[i] go from1 to 10000).
    
    2.Initialize a DP array of size 10001
    
    3.dp[i] -> the maximum points obtained while using numbers from 1 to i
    
    4.Now we have two decisions : pick that number (i) or not
    
    5.If we pick that number so dp[i] = dp[i - 2] + freq[i]
    
    6.Else dp[i] = dp[i - 1]
    
    7.So dp[i] will be max(dp[i - 1], dp[i - 2] + freq[i])
    
    8.Finally our answer will be dp[N - 1]