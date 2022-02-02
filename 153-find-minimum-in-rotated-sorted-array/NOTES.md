**Explanation**
​
This problem is similar to search in rotated sorted array. So here we will also use binary search, We will first calculate the mid and check which part is sorted left or right. We will maintain an ans variable which will be initially infinity. Now if left part is sorted means nums[s] < nums[mid] than we will take min of ans and nums[s] and now go to unsorted part bcz we already got the min of left part so we move s = mid +1 .
​
If right part is sorted mean nums[mid] < nums[e]  we will take min of ans and nums[mid]
And move to unsorted part that is left bcz we got the min element of sorted part so now we move to e = mid -1