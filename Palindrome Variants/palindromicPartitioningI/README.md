Intuition:-

    1.The structure of the question is quite clear that it promotes the use of recursion . The recursion approach of this question can be like: 
    we start iteration from beginning and step by step we increase the size of substr that we are checking for palindromes . Once the palindrome substr is found ,the substr needs to go to a vector/list storing those palindromes substr . This is how the brute recursion will work .
    
    3.The optimization of the above recursion is backtracking.
    
    4.A backtracking algorithm uses the depth-first search method. When it starts exploring the solutions, a bounding or a helper function is applied so that the algorithm can check if the so-far built solution satisfies the constraints. If it does, it continues searching. If it doesn’t, the branch would be eliminated, and the algorithm goes back to the level before. In simple words backtracking starts from some intermediate position where there is still a hope to get a new palindrome .
    
    5.In backtracking algo there is always a helper metod or a safe checker merhod which checks whether the built soution satisifes the conditions or not . This one thing has certainity of 100%.


Algorithm :-

    1.In backtracking, one thing is sure i.e a helper method. In our problem we will need a bool helper method which will check the palindrome conditions, let's name it as bool isPalindrome() .
    
    2.Now let's create some variables : result vector for storing all the substring which satisfies the palindrome condition , path vector for storing the ongoing substr which has the potential of satisfying the conditions of palindrome , start variable for storing the start position of the current substr , index i for traversing inside the substring and n fro storing the size of given string s.
    
    3.Now we search from start till the end of the string. Once we reach a position i such that the sub-string from start to i (s.substr(start, i - start + 1)) is a palindrome, we add it to our path variable. Then we recursively call the same method to execute the remaining substring . 
    
    4.Once we reach the end of the string, we add palindromes path into the result of all the possible partitioning .
    Remember that at position i , we find s.substr(start, i - start + 1) to be a palindrome and we immediately add it to path . Now think that there may be a position j such that j > i and s.substr(start, j - start + 1) is also a palindrome. 
    
    5.Thus now we need to go back to our start before adding s.substr(start, i - start + 1) to path and continue to find the next palindrome position after i . And after this evertime we simply need to remove or pop s.substr(start, i - start + 1) out of path to execute the backtracking algo .
    
    6.The steps we executed in the above step is none other than the famous dfs .