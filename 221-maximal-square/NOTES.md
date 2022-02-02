**Explanation**
​
Here we will maintain a dp vector of the same dimension as of matrix , and its i,j cell will denote the side length of a square whose bottom right corner is i,j. So how it will help us it that we start iterating the matrix from 1 row and 1 colum as , we are using it as bottom right corner , So for any 1 in matrix , we check the side of square above left and top left of current index , and we take min of all these 3 sides , than we add 1 into this minimum , As that will be equal to the side of the square whose bottom right corner is i ,j
​
For example
mat= 1 1 1 1   dp = 0 0 0 0
1 1 1 0            0 0 0 0
1 1 0 1            0 0 0 0
at i = 0 and j =0 we have 1 in matrix than we check the  here the top, left and top left are not avalable so max side square till now is 1 + min(0,0,0) = 1
​
That will be same for first row and first col
​
no i = 2 j = 1
​
mat= 1 1 1 1   dp = 1 1 1 1
1 1 1 0            1 0 0 0
1 1 0 1            0 0 0 0
​
we have i at i ,j and the min side of all square eneding at left , top and top left is 1
So we can make a square of 1 + min(1,1,1)  = 2 at i,j
​
whenever we calculate a side it take max of side
​
mat= 1 1 1 1   dp = 1 1 1 1
1 1 1 0            1 2 0 0
1 1 0 1            0 0 0 0
​
So in this way we can fill the full dp array, and than return square of max size
To avoid accessing invalid index for i=0 and j=0 we can create a dp or n+1 * m+1
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