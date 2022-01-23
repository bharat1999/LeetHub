**Explanation**
​
Here the idea is to keep track of the last occurence of each character because whenever we encounter a character again we will check if that character index is part of our current window so the current valid window will be from 1 + last occurence of that character and current index
​
for example a b c f a
idx 0 1 2 3 4
at j = 4 we again got a so current valid window will be from 0+1 =1 to 4
so its length will be 4 - 1  =3 plus 1 for the current char
​
So we will iterate over the string and keep track of last occurence of each character if character occured for first time it will be part of substring otherwise we will calculate the length by using the index of last occurence of that character
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