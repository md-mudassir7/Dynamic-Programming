Approach(recusrion)

    1.At any index in the array you can either pick that coin or skip it 
    
    2.You can pick the coin if its value is less than total amount to be made

    3.If you can pick then you can decide either to pick it not pick it

    4.If you pick the coin then you subtract the total amount with the value of coin at that index and  stay at that position itself to find out if there are more such coins that could probably give us the amount since we have infite flow of each coin

    5.If we dont pick then we just move to the next index in the array while the sum remians same

    6.The code gives better understanding


Approach(DP)

    1.This is a dynamic programming based solution of the above dp approach

    2.The comments in the code give better understanding


Approach(space optimised)

    1.This is a space optimised solution of the above dp code

    2.We use 2 array instead of a matrix to compute and at the end of every iteration we assign prev to current vector

    3.The code gives a proper understanding 