**Explanation**
​
It the brute force approach we are finding all the substrings and checking is they are a pallindrome or not and than taking max len pallindrome.But it is taking O(n) time as we have to check for each subtring .
​
So if we observe we have a overlapping subproblem of checking valid pallindrome substrings. So we will use a 2D dp array whose i, j tell if a subtring starting at i and ending at j is a pallindrome or not
​
So now we only have to use to loops to make all substrings
and check is s[i] == s[j] than we will check if j-i=1 means it is a substring of len2 so its true as s[i] == s[j] or we will check if the substring which start at i +1 and end -1 is a pallindrome or not  which we can do in constant time by our dp array, if its true we set
​
dp[i][j] = true and calcualte its len and if its ax we will store that substring
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