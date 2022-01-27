**Explanation**
​
Here we have two choices to take each number seperately or make a pair of two and if they are valid number between 1 to 26 than it can also be a choice . So here we will have a recurrence
​
f(i) = { 1 , i ==n because here we have decoded string in one way
0 ,  if s[i] == '0' because single character 0 is not valid
f(i+1) , taking one character at a time
f(i+2) , if substring s(i,i+2) is valid
}
​
Time Complexity =  O(2^n) because for each call we have to make atmax 2 choices
​
But we can see here that their are overlapping subproblems
​
​
let n = 5
i = 0
/   \
1      2
/  \    / \
2    3   3  4
​
we can see we are computing answer for i =2 and 3 , two times , so we can reduce this work by using as dp array where dp[i]  is the number of ways to decode a string starting from ith index
​
​
​
​
​