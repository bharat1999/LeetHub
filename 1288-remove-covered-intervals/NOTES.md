**Explanation**
​
Here we have to check which interval lie in another , to check that we have to compare the starting and ending of intervals . So to do that easily we will first sort he array acc to starting value of the interval , that way we do not have to run two loops to check for each interval with all other , So we first set start and end = -1
and than start iterating over the intervals , for each interval if start and end of interval is greater than current start and end it means it do not lie in current interval so we increment ans and also update the start
For each interval we also update the end by taking max of end and curren end
​
For ex  [ [ 1,4] ,[ 3,6] ,[2,8]]
​
ans = 0 start = -1 end = -1
​
Interval = [1,4]
​
1> -1 and 4 >-1 so its new interval increment ans and update start
ans = 1 , left = 1 , right = 4
​
Interval [2,8]
​
2>1 and 8>4 so its new interval
ans = 2 left = 2 right 6= 8
​
Interval [ 3.6]
​
here 3>2 but 6<8 so it lie in prev interval so no increment
ans = 2 left = 2 and right =8
​
Ans = 2
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
​
​
​
​
​
​