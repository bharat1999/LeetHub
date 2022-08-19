**Explanation**
​
We will use a map with value as a min heap . Than we iterate the array from right to left and check if we have a sequence starting from num[i] + 1 , if is is not than we create a new sequence starting from that number and add its length as 1
​
Is it is avl than we have to make a new sequence with length = smallest sequence of num[i] +1  + 1
​
Smallest sequence bcz
for example 1 2 3 3 4 5
x = 5
seq  = 5
​
x = 4
seq = 4 5
​
x= 3
seq = 3 4 5
​
x =3 we again get 3 so make new
​
seq = 3 4 5 , 3
​
now x = 2 now we have 2 choice for it but if we add it to 3 4 5 than ans will be invalid cause 3 will be left alone That why we are using min heap to keep track of length of sequences starting from that number