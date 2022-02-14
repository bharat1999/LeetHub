**Explanation**
​
Itnthe brute force approach we are finding all the substrings and checking is they are a pallindrome or not and than taking max len pallindrome.But it is taking O(n^3) time as we have to check for each subtring .
​
So if we observe we have a overlapping subproblem of checking valid pallindrome substrings. So we will use a 2D dp array whose i, j tell if a subtring starting at i and ending at j is a pallindrome or not
​
So now we only have to use wo loops to make all substrings
and check is s[i] == s[j] than we will check if j-i=1 means it is a substring of len 2 so its true as s[i] == s[j] or we will check if the substring which start at i +1 and end at j -1 is a pallindrome or not  which we can do in constant time by our dp array, if its true we set
​
dp[i][j] = true and calcualte its len and if its ax we will store that substring
​
​
but we will start iterating from substring from end bcz if we start from begin we will encounter some dp index which have not been filled
For example i =0 and j =3 we need dp[1][2] but it will not be filled as we have not yet iterated on i=1
​
but if we start i from n-1 we will not encounter this
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