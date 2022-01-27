**Explanation**
​
Here the idea is to take care of the number of arithmetic slices available till the current index
.But how will that help us , let's take an example
​
1 2 3 4 5
​
here at i = 2 we have 1 valid slice possible
Now we have to check if at i =3 slice if possible or not
if it is possible we will have 2 slices possible till i =3 because one if index (1,2,3) and the other will be (0,1,2,3)  so here we will keep a DP array whose ith index represent the number of slices possible till that extend and we will maintain an ans variable and no of slices ending at each index.
​
So our relation will be
​
if (current index is valid part of sequence that it a[i] - a[i-1] == a[i-2] - a[i-3]
than d[i] = 1 + dp[i-1] as 1 for the current we find the the dp[i-1] for all possible slices after including current element also
​
​
​
​
​
​
​
​