**Explanation**
​
the node with max indegree will be the answer cause that will be the root or centroid of the of the tree with min height and it can be also proven that their can be atmax 2 mst
​
so we first create adj list than create indegree array and than start with the leaf node means having in degree one than we will keep goind to inner of tree and reducing their indegree by 1 meaning we are removing leaf we will push each element of current level in and vector and after every level traversal if q  is not empty we will clear our ans vector