**Explanation**
​
**One way using LCS**
​
WE can calculate the LCS using DP and than our answer will be the sum of len of both string - 2 *LCS . as that will be the numebrs of steps requried . Because if For example both string completely mismatch than no of deletion will be m+n . Suppose LCS = 1 means we have to do 1 less deletion in both the strings . So this is how this formula works
​
**Without LCS**
​
This question is very similar to Longest common subsequence , their we have to check the longest common subsequence and here we have to make both subsequence common.
​
So our base case here will be when both string are iterated and if any one string is iterated , the answer will be the length of remaining string , bcz that will be the number of deletion required
​
For recursive case if both char are same we do not need any deletion an we go to next char of both strings otherwise , we have to delete 1 char so we add 1 to ans and take minimum of the answer by deleting either 1 char of word1 or word2