**Explanation**
​
Here we can break our problems as the number of ways to reach nth stair = no of ways to reach from n-1 and n-2th stair. So we can solve it recurisively or iteratively and optimise it using dp
​
Relation = f(n) = { 1, n=1
2 , n=2
f(n-1) + f(n-2) , n>2
}
we can store these in DP vector and calculate dp[i] = dp[i-1] + dp[i-2]
So our Time Complexity in O(n) and Space Complexity is O(n)
​
We can furthure optimise our space as we can see we only need two prev values i-1 and i-2 so we can save them in variables and make space complexity constant
​
​
​
​
​