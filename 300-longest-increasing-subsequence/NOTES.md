**Explanation**
​
Their are multiple approaches for this problem
​
**DP**
​
Dp approach is that we will initially will a dp vector with 1 as 1 will be the minimum LIS,
Now we start iterating all subarrays ending at 0 till n-1. Than we  start a loop j=0 to i-1.
Than if nums[i]> num[j] than we update dp[i] = dp[j] +1
​
And in the end we take max of the dp
​
**Greedy Binary Search**
​
Our approach is a greedy approach with binary search where we start creating the LIS so we start from the first element and insert them in our vector till current element is greater than the last element of our vector. Now we whenever get a smaller element  we search in our ans vector which the next greater than current element and we replace that with current. This is done because the current element is smaller than that max of ans vector so that can allow furthur more elements to be part of LIS
​
for example 1 2 8 3 4 5 6
​
​
Our ans till i =2 is 1 2 8
​
Now at i = 3 we got 3 but is smaller than 8 so if we replace 9 with 3 we can get furthure 4 5 and 6 as our part of LIS . So this greedy approach works and vector size after whole array iteration is the answer . Its time complexit is O(NlogN) N for iterating the array and logN for the binary search its better than DP because its O(N^2)
​
​