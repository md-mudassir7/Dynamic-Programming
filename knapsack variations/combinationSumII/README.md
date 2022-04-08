Approach1

    1.Recusrion is used to solve this question

    2.At any index we can chose the element at that index or discard it

    3.To handle the duplicates we sort the candidates array before passing it to the solve function and run a for loop to discard the duplicates in the array 

    4.The code gives a better understanding

Approach2

    1.Here we keep track of the uniqueness of the resultant array using a map

    2.We insert into the result vector  only if the temp vector has not been seen in the map

    3.To handle duplicates we run a while loop