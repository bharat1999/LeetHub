**Explanation**
​
Brute force , we can make all possible prefx+ suffic pair and insert in trie
for ex in case of apple
it can be a,e ap,e and so on it will take 3 loop for all cases and one for insertion
​
Optimal way we can just make all possible suffix and add them in front of suffix
​
for example for apple we will make
e#apple . le#apple and so on and when searching we will make a string like suffix+#+prefix
​
for example prefix = a and suffix = e
we make e#a we know trie have e#apple so we stop searching at e#a so that we will can reduce loop