**Explanation**
​
Here to make different BST we will have to make each i as the root and than make left subtree with values ( 1 to i-1) and right subtree with value (i+1 to n)
​
So for ith as root the number of structurally unique tree will = tree from leftsubtree * trees from rightsubtree . We multiply this because each tree of left will form a  unique tree with each tree from right.
​
So our relation will be
​
ans=0
for(int i =1 to n)
f(i) = { 1 , i <=1 , as for one node we have only one possible tree
ans+= s(i-1) * f(i+1)
}
But we have to find unique structure tree irespective of values
So instead of i+1 we can pass the number of nodes that can be possible in left and right
So for right we will have n-i nodes
​
Now this will have multiple overlapping problems So we use a lookup vector to keep track of already calculated tree with root as i