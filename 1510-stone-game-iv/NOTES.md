**Explanation**
​
![image](https://assets.leetcode.com/users/images/01c43869-37d7-4612-a611-5e8ba0f20610_1642825595.5490935.png)
​
​
​
​
Here we hvae to check if we can give a number of stones to bob so that he can never win.
For that we will make a bool dp vector , and store if with the current number of stones we can deduct some numbers and give losing state to dp.
​
for example at n=1 dp[1] = true;
so at i=2 we cannot get any state which can make the opponent lose bcz we can only give 2-1 = 1 state to bob and n=1 is a winning state
​
​