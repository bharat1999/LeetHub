Iter i=0  max = 3 last = 0
Iter i = 1 max = 3 last = 0
iter i = 2 max = 3 last = 0
iter i = 3 max = 3 last = 0
now i == max means at curretn index the max len partition end we do not need to check other char as we are taking the max idx
​
ans + = 3 - 0 + 1 = 4 len
​
iter i =4 max =6 last = 4
iter i = 5 max = 6 last = 4
iter i = 6 max = 6 last = 4
again i = max so add to ans
ans = 6 - 4 + 1 = 3
​
result = [ 4,3]
​
iter i = 7 max = 8 last =7
iter i = 8 max = 8 last = 7
again i == max
ans = 8-7+1 = 2
result = [4,3,2]
last = 9
​
iter i = 9 max = 9 last = 9
again i = max
ans = 9 -9 +1
result = [4,3,2,1]
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