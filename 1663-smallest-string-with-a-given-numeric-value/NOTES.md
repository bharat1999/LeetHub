**Explanation**
​
Here we can do greedy approach , we have to think it as reverse , we have to make smallest string , that mean we need smallest char at begining so to put smallest at begin , we have to put max possible char at the end to reduce the required sum for initial char
​
So for k>26 we greedily want to put z but we also have to check that after using z can we put remaining char for ex n = 3 and k = 27 if we put z than k will be 1 and we have to put 2 more characters so its not possible . So we have to check if k-26>= n-i , this will check if after using z do we have sum remaining for n-i charcters
​
For else case we will check the largest character possible at that place , that will be finded as subtract the number f characters remaing after current char
​
For ex k = 21 and 3 char remaining so for current char we need to put a char after which we will have atleast 2 sum remaining so we check it as k-(n-i)