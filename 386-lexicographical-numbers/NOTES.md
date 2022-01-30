**Explanation**
​
We know that for lexicographically order for each digit we will add trailing zero till the no is less than n
​
For example if n = 101
we will print 1 10 100 first than we will print 11 110 and so on
So we will maintain a cur var which is initially =1 and in each iteration we will add cur to our and after that multiply cur by 10 than we will check if cur exceed n if not we do nothing but if it does , we will divide it by 10 to go back to previous , now we have added all the elements starting from a no to our answer so we have to remove all trailing zeroes before going to next no
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