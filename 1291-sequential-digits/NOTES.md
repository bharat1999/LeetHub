**Explanation O(1)**
​
Here we can go brute force and create all possible numbers and check is they lie in range or not , because when generating numbers the loop will be from 1 to 9 only.
​
so we will have two loops one to set the first digit and next to create sequential number starting from that digit
​
after creating number we will check if that lie in our range or not and than add it to our answer vector.
​
This will be considered constant time as both loops only run from 1 to 9
​