**Explanation**
​
Here we will precompute a prefix array , where prefix[i][j] is the sum of all elements of the square where top left corner is 0,0 and bottom right is i,j
​
Now whenever we have to find area of a region we can easily calculate
​
​
bottomrightPrefix = prefix[row2][col2] = it is the sum of all elements till i,j
topPrefix = (row1-1>=0)?prefix[row1-1][col2]:0; = it is the sum of all elements of rows above our rectangle starting row , we have to subtract it as our bottomright have all elements of the above region also
leftPrefix = (col1-1>=0)?prefix[row2][col1-1]:0; = it is the sum of all elements of col before before starting col of our rectangle , we have to subtract it as our bottomright have all the elements of left region
topleftPrefix = ((row1-1>=0 and col1-1>=0)?prefix[row1-1][col1-1]:0); = as we will subtract top and left prefix topleft will be substracted twice so we have to add it
​
Ans = bottomrightPrefix - topPrefix - leftPrefix + topleftPrefix
​
​
​
​
​
​
​
​
​