Approach

    1.Recusrion is used to solve this question

    2.At any index we can chose the element at that index or discard it

    3.If we discard we just call the recusrion with ind+1, and if we choose then we add it to our temporary vector and decrease the target by the value of array element at index ind

    4.Base cases are if the index reaches the end of array or if the target is less than 0 we just return

    5.If the target is zero then we push the temporary vector into the actual resultant array 