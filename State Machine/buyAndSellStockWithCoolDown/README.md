Approach

    1.At any index in the array we can either buy or not buy or if we have bought any stock previously we can sell or not sell

    2.To keep track of wheather we have bought any stock or not we can use a variable canBuy which tells us if we can buy the current stock or sell it

    3.If we can buy then we have 2 options we can buy the current stock or not buy it.If we decide to buy then we decrease the profit with the value of current stock and update canBuy to 0 since we cannot buy anything until we sell that stock,else if we decide not to buy we can move on with our canBuy as 1 since we have to buy anything at some point

    4.Similar is the case with sell but when we decide to sell we add the profit with the price of the stock on that index

    5.When we start the recursion with the first index we can obvoiusly ony buy that stock since we dont have any elements before it

    6.The only change here is that when we can sell and we decide to sell then we move 2 steps ahead inorder to skip the cooldown day 

    6.The comments in the code give a proper explaination
