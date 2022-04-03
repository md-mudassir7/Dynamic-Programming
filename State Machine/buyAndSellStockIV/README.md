Approach(class Solution1)

    1.This is similar to buyAndSellStockII but we are restricted to k transactions

    2.We can add another parameter(noOfTransactionRemaining) which can limit the numberoftransactions we do

    3.We set the varialbe to k initially and when this becomes 0 we stop the transactions

    4.Here also we have a 2 conditions we can buy or not buy described by the variable canBuy

    5.If we can buy then we can decide to either buy or not buy,if we decide to buy then we update canBuy to 0 since we should sell this buy before buying again and noOfTransactionRemaining reamins constant as a transaction can only be complete if we have sold the stock hence it remains the same and we move to the next index, if we decide not to buy then canBuy and noOfTransactionRemaining will still be the same and we move to the next index

    6.If we cannot buy then we can decide to either sell or not sell,if we decide to sell then we update canBuy to 1 since we can buy the stock now and decrease noOfTransactionRemaining by 1 since one transaction is complete and we move to the next index,if we decide not to sell then canBuy and noOfTransactionRemaining will still be the same i.e we can look for some other day to sell the stock

Approach2(class Solution2)

    1.If the value of k is greater than length of array/2 then its obvious that we can make as many transactions we want hence we just copy paste the code of buyAndSellStockII

    2.Else we will generalise the solution of buyAndSellStockIII where we were allowed only 2 transactions 

    3.We create 2 arrays of size k denoting buy and sell and we do the same thing we did in buyAndSellStockIII problem

    4.The comments in the code give a better understanding