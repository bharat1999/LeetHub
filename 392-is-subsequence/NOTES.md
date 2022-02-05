**Explanation**
​
**Two Pointer**
​
Here will use two pointer starting from 0 for each string and we start iterating both the string if str1[i] == str2[j] thats means the we found a char of str1 in str2 so we icnrease our i pointer and the j pointer will be increased in every case.
​
Time Complexity O(n)
​
**DP**
​
Here we will find the LCS of str1 and str2 and check is that is equal to the length of str1 than it is possible to get str1 as subsequence of str2 . So we implement it calculating LCS using DP
​
Time Complexity O(n^2)
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
​