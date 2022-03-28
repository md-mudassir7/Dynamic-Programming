Apporach

    1.The problem is similar to LIS

    2.First we sort the array and then calculate the LIS of the array using dynamic programming

    3.The dp array at any index will store the longest increasing subsequence until that index

    4.After we are done with updating our dp array we calculate the maximum value of that array and using this maximum value we create the array that is required using some if conditions(lines 21-25)


Dry Run

    arr = [3,4,8,1,2,6]

    after sorting arr = [1,2,3,4,6,8]

    Dp array = [1,2,2,3,3,4] max here is 4 

    We start iterating the dp array from the back because it eases our task

    ans = []

    1st iteration: dp[5]==max and ans is empty hence ans = [8] (remember its arr[i] which we are pushing) max-- (max = 3)

    2nd iteration: dp[4]==max but 8%6 is not zero hence we do not need that 

    3rd iteration: dp[3]==max and 8%4==0 and hence we add it to ans hence ans = [8,4] and max--(max=2)

    4th iteration: dp[2]==max but 4%3 is not zero hence we do not need that

    5th iteration: dp[1]==max and 4%2==0 and hence we add it to ans hence ans = [8,4,2] and max--(max=1)

    6th iteration: dp[0]==max and 2%1==0 and hence we add it to ans hence ans = [8,4,2,1] and max--(max=1)

    Hence the ans = [8,4,2,1]

    Try running over multiple test cases for better understanding