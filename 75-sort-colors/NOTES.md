It is example of dutch flag problem
​
here we will keep two pointer intially one at begin and one at end to keep track where to insert the min and max value in this case 0 and 1
​
initially low= 0 and high = n-1
​
ex 2 0 2 1 1 1
​
we start from i =0
​
we have two so we swap it with value at high and make high --
​
now array is
​
1 0 2 1 1 2
low =0 high = 4
​
now we will not increment i because the swapped value can be 0 and we have to take it back
​
now we have 1 at i =0 so we will do nothing
​
i = 1 we have 0 so we need to take it to low index
so we swap value at low with i
​
and increment both i and low because it is gauranteed that current value at either 0 or greater