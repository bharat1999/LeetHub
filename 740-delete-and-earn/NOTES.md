Here the problem is similar to house robber as we can't take the adjecent values.
but instead of adjecent indices we can't take adjecent values and here we can also take
the same values , becuase for same value we delete neighbours only once but take them always
​
So we create a array of 10001 bcz of constraint and add the points of each number in it
for example at index 2 we will add 2 equal tot the items it occur in array
​
for example 2 2 3 3 3 4
​
our sum array = 0 0 4 9 4   (as 2 occur 2 time 3 occur 3 time and 4 occure 1 time)
index = 0 1 2 3 4
now we have a dp array
and the dp[i] = max(sum[i] + dp[i-2] .dp[i-1];
​
// as sum of 0 is zero and sum of ones is sum[1]
initially dp[0]=0 and dp[1] = sum[1]
​
for i=2 i<n ; i++;
​
dp[i]= max( 4+ dp[0] . dp[1]) = max(4,0) = 4
​
simalarly it will work for the 10000 terms and we will get the answer
​
​
​
​
​