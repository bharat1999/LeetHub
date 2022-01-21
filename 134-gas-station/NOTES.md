**Explanation**
​
At first we check if thier is enought fuel to complete the cycle or not , so we find the total gas in tank after a cycle if it is negative means we do not have any valid starting point so return -1.
​
If its possible we will have two variable start to store the answer and tank which will be initially zero and store the cur gas we have left with if at any point it become negative that means with current start point our answer is not possible so we make our start = i+1 and our tank =0;
​
is its not we add the gas to tank