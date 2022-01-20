**Initial Intution**
​
Here the initial intution was to check all possible speeds from 1 till the max size of piles
of bananas and whenever a speed is possible it is the answer
but in the worst case it will run till end so the time complexity will be
​
O(n*m) -> n to check if a speed is valid and m for all possible speed where m is max pile
​
**Optimal Approach**
​
Here our search space is monotonic, so we can apply binary search
as if suppose we can eat all banana with speed s than it is also possible to eat with all speed
greater than s so we ignore those and search in search space from 1 to s
​
Similarly if a we cannot eat all banana at speed s than it is not possible to eat for
any speed less than s than we will search in s+1 to m.
​
This make our complexity O(nlogm) -> Where n is time to check valid speed and log m to find the minimum speed
​
​
​
​
​