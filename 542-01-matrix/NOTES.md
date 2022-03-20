**Explanation**
​
In this question we know that distance of 0 is zero and for ones we have to find . So here we build our solution as first setting all distances of 1 as infinity and than start from top left corner , than for every one we will find answer using the top and the left cell.
​
After that we once start from bottom right and search for minimum distance of a 0 from below and right
​
For example our matrix is
​
0 0 0                                         0 0 0
0 1 0     and distanc matrix is   0 inf 0
1 1 1                                          inf inf inf
​
than for i=1 and j = 1
value at i j = infinity and value from left and top is 0 so we add 1 to that and take minimum
​
than we repeat the process for all cells
​
​
​
​
​
​
​
1