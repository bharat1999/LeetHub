**Explanation**
​
Here we calcualte the number or continous ones in a colum from left
for example
for row 1 0 1 1 1
dp for this row will = 1 0 3 2 1
Now this will help us as for each cell of a row we check in other row for that column for lowest values
for example
​
1 0 1 1 0    dp = 1 0 2 1 0
1 0  1 0 0             1 0 1 0 0
​
now for i =0 and j =0 we search in j = 0 column for the min value because that will be the height of current rectangle
so jo j= 0 it will be 1 but in between this iteration anytime we get 0 than it will stop as thier cant be break in rectangel