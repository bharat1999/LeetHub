**Approach 1 . O(m+n)**
​
As it is row and column wise sorted, we an start searching from top right corner
and if target is less than current we go left otherwise down.
​
**Approach 2. (log(m+n))**
​
Here if we consider this matrix as 1d array it is sorted in increasing order so here we can modify binary search to work on 2d matrix
​
here n = no of rows m = no of colums
​
initialy s=0 and e = n*m -1;
​
so after calculating mid we can get the index of middle element
​
as row = mid/m; and col = mid%m;
​
​
​
​
​
​
​