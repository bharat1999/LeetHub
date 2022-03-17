Example
​
Here score is related to the depth of each level
​
For ex ((()))()
​
intitially score = 0
than again we get ( so stack == 0 , 0
again we get ( so stack = 0,0,0
now we got ) so we calculate score and pop top
stack = 0,0
score =1
​
As we are at lowest level score = 1
now we again got )
Our score =1 so
final score for this level = score till current level which will be at stack top + 2*score
so current, top = 0 and score = 2*1
again pop
stack = 0
score = 2
again we get ) so
score = 2*2 = 4 + 0 and top is 0
now score = 4 and stack is empty
​
now we get ( means starting of current new level
so we first push current score and than reset
stack = 4 score=0
​
now we get )
so we calculate score = top + max(2*0,1)
= 4 + 1
=5
again we pop stack and it become empty