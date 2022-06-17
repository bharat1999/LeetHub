**Explanation**
​
I've used DP to solve this, the dp has 2 dimensions, the node and the state of the node
​
the state of the node can be
​
0: not observed
1: observed
2: has a camera in it
​
1: If the node is observed we can either put a camera on it and put children as observed, or not put any camera on it and mark children as not observed
​
2: If the node has a camera in it the children are going to be observed
​
0:if the node is not observed we can either put a camera on it or put a camera on either one of its children
​
since for memoizing the DP I needed to identify which node to memoize. I've numbered the node at the beginning to identify it
​
​
Greedy Approach
​
We will fill from bottom up we check if child need cameraor not than we put camera
if node is not covered and do not have parent we put camera their