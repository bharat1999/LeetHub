**Explanation**
​
Here we have to check if s2 contain a permutation of s1, so we will check s1 size substring of and to check if they are permution of s1 , so we will iterate over windows of size of s1 of s2.
​
And to check if these substring are permutation of s1 we will keep track of frequency of s1 and s2 using array as size is fixed to 26.
​
So first we will check first window of size s1.size and check it
​
After that we will check from i = s1.size till <s2.size and in each step
increase frequencu of ith character of s2 and remove the first character of last window and again check for equality