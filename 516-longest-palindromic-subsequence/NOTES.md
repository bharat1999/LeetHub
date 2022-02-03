**Explanation**
​
Here to make subsequences we have to choice if we have to take current char or not.
So here as we have to check for pallindrome , we will take two pointer start and end which will be initially 0 and size -1 and than we will recursively check if char at start and end are equal or not than we have three case
​
1. If they are equal their is only one way to get max that is ans will be 2 (bcz as 2 are same ita guranteed to get 2 size pallindromice subsequence) + ans from remaining string that is from start+1 to end -1.
2. We ignore start char than we take ans from start+1 and end
3. We ignore end char than take ans from start to end-1
​
As 2 and 3 case are for not equal senarios we take max of their returned values
​
So our recursive relation is
​
f(st,end) = ( 1 , st == end , 1 size always pallindrome
0 , st>end , no subsequence possible
if(s[st] == s[end]
ans = 2 + f(st+1,end-1)
else
ans = max( f(st+1,end) , f (st , end-1)
)
How here our time complexity will we O(2*=^n) becuase we are doing atmax 2 calls for each case
So how we can optimise , here we can observe that we have overlapping subproblems means we have to compute the ans for same st and end multiple times , So we can use lookup table to store already computed answers to optimise our approach here
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
​