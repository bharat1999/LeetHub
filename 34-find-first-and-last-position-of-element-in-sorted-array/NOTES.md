In this we have to find the index of first and last occurence
​
we know binary search give us the index of target so where we will modify it a little so we use binary search 2 times
​
In 1st iteration when we find any occurence of target we will set end = m-1 so that we can check occurence of target before the current index so this way we will get index of first occurence
​
similarly in 2nd iteration whenever we found we will set s= m+1 to get the next occurence of target and hence getting final value