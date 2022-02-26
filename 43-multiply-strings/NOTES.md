**Explanation**
​
Here we will use general vertical multiplication and multiply number one by one from right to left. To store these answers and modify the result according to next level we will store partial result in res string
​
For example 123 and 23
Iteration i = 2
j = 2
res[2+2+1] = 3*3 = 9; res = 00009
j= 1    res[1+2+1] = 2*3 = 6 res = 00069
​
So after one level res = 00069 here ith digit means 9 will be fixed
​
Iteration i = 1
j = 1
res[1+1+1] += 2*3 = 6  now we already have a no at this index so it will be updated
ans = 6+6 =12
Now as it exceed 9 so we carray forward 10 place to prev
res = 00129
j = 0
res[1+0+1] = 2*2   = 4 again its populated so it will be updated
as res[2] = 1 +4 = 5
res = 00529
After this level ith palce that is 2th place is fixed
Same will work and we wiil get the answer
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