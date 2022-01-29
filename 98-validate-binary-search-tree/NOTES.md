**Explanation**
​
In BST we have to check if all node in left subtree have value less than root and more than root for right subtree
​
So we will keep two variables min and max and they will be used to set the lower and upper bound for each recursive call.
​
So now when we visit a node we will check if its in the range of min and max or not
​
When going to left subtree we make the root as max bcz that must be the maximum value for the left tree and when when going to right subtree we make root as the minimum value
​
​
​
​