**Explanation**
​
Let the input be [2,2,2,3]
We iterate vertically through the input all along 32 times (integer is represented in 32 bits)
2-> 1 0
2-> 1 0
2-> 1 0
3-> 1 1
​
We find the sum of each ith vertical level. (i in range 0 to 31)
​
If the sum is divisible by 3 then the ith bit in the single occuring number is 0 ( since each number except one occurs three times so the bitsum will be 3(some constant)
​
if the sum is not divisible by three then the ith bit in the single occuring number is 1 (since the bitsum in this case will be 3(constant) +1
​
Since the ith bit is set in the single occuring number, you have to build the number by setting the ith bit when the bitsum in ith place is not divisible by three.