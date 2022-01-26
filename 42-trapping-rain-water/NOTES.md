here the trick is that
​
for every tower we have to check what is the highest tower to its left and right
so water can only rise till minimum of both those tower values and its value will me
​
min(left,right) - hieght of current tower
​
if we search for every array it will be n^2 but we can precompute left and right array
​
and do it in o(n)