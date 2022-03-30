Apporach

    1.We create a boolean 2d dp array of size nxn where n = size of the string

    2.dp[i][j] denotes if the substring starting from i and ending at j is palindrome

    3.The bottom triangle of dp will be empty since in that triangle i>j and its illogical that a string can start at index which is greater than the index where it is supposed to end

    4.The substring s[i:j] is palindrome is s[i]=s[j] and s[i+1:j-1] is also a palindrome hence we check these 2 conditions and assign dp[i][j] the correct value

    5.Here we should understand how to traverse only the upper triangular matrix of the matrix 


This [link](https://www.youtube.com/watch?v=XmSOWnL6T_I) gives much better understanding of the above approach