**Explanation**
​
Here the pattern is like that of a number
for example 123
can be written as 1 *100 + 2*10 + 3*1
Here its the sum but with character for AB
We have A*26 + B*1
As A =1 So 1 * 26+ 2 = 28
​
So here 26 is the base
​
Steps
​
1.We initialize result with 0 initially
2.Than we iterate over the string left to right and than calculate digit value of each char
3.Than we will multiply our result * 26 and add current digit , this is bcz for example the length of string is 3 than the leftmsot char value should be multiplied by 26 two times
So as the leftmost digit is added in the first iteration of the loop  it will be multiplied by 26 two time for a string of len 3
​
​
​
​
​
​
​
​
"BC" = (2)26 + 3
"BCM" = (2(26) + 3)26 + 13