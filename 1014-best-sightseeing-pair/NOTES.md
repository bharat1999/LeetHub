​
ex 8 1 5 2
​
dp = [8]
score = 0 infinity
​
for j = 1
​
score = max(-inf, 8 + 1 -1) = 8;
dp[i] = max(8,0) = 0;
​
for j = 2
​
score = max (8, 8 + 5 - 2) = 11
dp[i]  = max (8,3) = 8
​
for j = 2
​
score = max(11 , 8+2-3) = 11
dp[i] = max(8, -2) = 8
​
So our answer is 11
​
**Explanation Time = O(n) Space = O(1)**
​
We can furthur optimise our code in space because as we see our relation is only dependent on prev value of dp so instead of using a dp vector , we can have maxleft var and update it on each step. This will make our appraoch space constant
​
​
​
​
​
​
​
​
​
​
​
​