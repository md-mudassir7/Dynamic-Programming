Approach

    1.We create an array dp of size n where n is size of array

    2.At any index i dp[i] stores the longest increasing subsequence uptill that index i

    3.So to find dp[i] we loop again from 0 to i with iterator j and check if arr[i]>arr[j](since it has to be increasing) and if adding 1 to 
    dp[j] makes it greater than dp[i] which means it is increasing 

    4.If yes then we assign dp[i] = dp[j]+1