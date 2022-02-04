its same as find subarray with k sum so whenever we approach 0 we consider it as -1 and it
​
so whenver we get same prefix sum it mean the element between the last occurence of same prefix sum and current is 0 so that is the answer
​
example
​
array   1 1 0 0 1 0 1 0
prefix  1 2 1   here prefix =1 occur again so max length will be i - index of prefix[1] so curmax= 2 - 0 = 2
​
array   1 1 0 0 1 0 1 0
prefix  1 2 1  0   Now we encounter 0 so in this case we will consider whole string till now
​
curmax = max(2,3+1) = 4 is current index +1
​
array   1 1 0 0 1 0 1 0
prefix  1 2 1 0  1    again one occur so curmax =max(4,5-first occ of prefix 1) = max(4,4-0) =4
​
array   1 1 0 0 1 0 1 0
prefix  1 2 1 0  1 0  again we encounter 0 so in this case we will consider whole string till now
​
curmax = max(2,5+1) = 6 is current index +1
​
array   1 1 0 0 1 0 1 0
prefix  1 2 1 0 1 0  1    again 1 so curmax=max(6,6-0) = 6
​
array   1 1 0 0 1 0 1 0
prefix  1 2 1 0  1 0 1 0  again we encounter 0 so in this case we will consider whole string till now
​
curmax = max(6,6+1) = 7
​
so our answer is 7