**Explanation**
​
The idea is always keep an max-product-window less than K;
Every time add a new number on the right(j), we reduce numbers on the left(i), until the subarray product fit less than k again, (subarray could be empty);
Each step introduces x new subarrays, where x is the size of the current window (right - left  + 1);
​
example:
​
I/p: [ 10, 5, 2, 6 ], k = 100
​
right = left = 0;
prod = prod * 10 = 10;
res = res + 0 - 0 + 1 = 1;  // subarrays - [ 10 ]
​
right = 1;
prod = prod * 5 = 10 * 5 = 50
res = res + 1 - 0 + 1 = 1 + 1 - 0 + 1 = 3; // subarrays - [ 10 ], [ 5 ], [ 10, 5 ]
​
right = 2;
prod = prod * 2 = 50 * 2 = 100;
prod > k;
prod = prod / nums[left] = prod / nums[0] = 100 / 10 = 10;
left++;
res = res + 2 - 1 + 1 = 3 + 2 = 5; // subarrays - [ 10 ], [ 5 ], [ 10, 5 ], [ 2 ], [ 5, 2 ]
​
right = 3
prod = prod*6 = 10 *6 = 60
prod<k
res = res + 3 - 1 + 1 = 5 + 3 - 1 +1 = 8 // subarrays - [ 10 ], [ 5 ], [ 10, 5 ], [ 2 ], [ 5, 2 ]          [6], [2 ,6] , [ 5 ,2, 6]
​
​
​
​