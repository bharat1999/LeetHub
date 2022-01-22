**Explanation**
​
Here the problem can be solved by modifying the Kadane's algorithm , Here we have two possibilities the answer can be continous subarray like from indx 0 to 3 or the ans can be the subarray having some elements from front and some from end like from indx 0 to 3 and 5 to 6
​
So what we can do is we will also calculate total sum and the minimum sum  subarray with the max sum ,
​
If the maxsum is negative means all element are negative than we will return the value of max sum.
​
Now how this minsum will help us
​
take an example
​
5 4  -1 0 5 4
​
here our max sum = 9 and min = -1,
We can see here the max sum subarray will be 5 4 5 4
It can be seen that if we deduct the min sum from total sum we will get our answer
​
So after finding all the values our answer will be the max of maxsum and totalsum - minsum
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
um - minimum sum