Approach(class Solution1)

    1.At any index in the array we can either buy or not buy or if we have bought any stock previously we can sell or not sell

    2.To keep track of wheather we have bought any stock or not we can use a variable canBuy which tells us if we can buy the current stock or sell it

    3.If we can buy then we have 2 options we can buy the current stock or not buy it.If we decide to buy then we decrease the profit with the value of current stock and update canBuy to 0 since we cannot buy anything until we sell that stock,else if we decide not to buy we can move on with our canBuy as 1 since we have to buy anything at some point

    4.Similar is the case with sell but when we decide to sell we add the profit with the price of the stock on that index

    5.When we start the recursion with the first index we can obvoiusly ony buy that stock since we dont have any elements before it

    6.The comments in the code give a proper explaination

Approach2(class Solution2)

    1.This is a bottom up approach of the above recursion solution

    2.The code gives proper understanding

Approach3(class Solution3)

    1.The second solution shows that we will buy the stock everytime when we know that the next day its value is higher 
    i.e(prices[i+1]>prices[i])

    2.We keep on adding the profits i.e(prices[i+1]-prices[i]) everytime we encounter the above condition

    3.This is a greedy approach not a dynamic programming approach

Click [Here] for the intuition of approach 3(https://www.youtube.com/watch?v=3gtcRtvDCpA)