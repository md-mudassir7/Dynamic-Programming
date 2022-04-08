Problem [link](https://leetcode.com/problems/triangle/)

Approach

    1.We can modify the triangle in place as we did in minimumfallingpathsumi 

    2.The catch here is that for the last element of every row in the triangle its upper value does not exist 

    3.Hence the falling path sum for that element will be the sum coming from its diagonally previous element([i-1][j-1])

    4.Else it is the the minimum falling sum coming from its upper value and diagonally previous value

    5.The code gives a proper explaination 