**Explanation**
​
Even numbers can be divided multiple times until it converts to an odd number.
Odd numbers can be doubled only once as it converts to an even number.
Therefore, even numbers can never be increased.
Follow the steps below to solve the problem:
​
1. Traverse the vector and insert elements in set to maintain sorted list
2. If current element is even add to set as it is and if its odd multiply by two and than add
. This will avoid the use of 2nd operation futhur.
3. We will divide elements of set by 2 untill the greatest element become odd , bcz we cannot decrease the maximum furthur. After each division we modify the ans as
ans = min(ans , *s.rbegin() - *s.begin())
This work bcz rebegin will give the max of set and begin will give the current smallest.
4. If the maximum element present in the Set is odd, break the loop.
5. Print the minimum deviation obtained.
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