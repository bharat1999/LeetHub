**Explanation**
​
TopoSort
​
we will first find the topological order of graph and than assign index to each node in graph
​
for example topo order is
0 1 5 3
than index will be 0 1 2 3
​
now we will check neighbour of each node
now suppose i = 5 whose index is 2 and its child is 0 whose index is 0 that means itsa back edge so return empty array otherwise the topoarray
​
​
**Kahn Algo**
​
This is based on intution the first element in topo order will be the one that has no prerequisite that means it should have 0 indegree if multiple node has 0 in degree it doesnt matter so we start from node having 0 indegree than go to their child and reduce thier indegre by 1 and add those nodes to queue having 0 indegree and also add the current node to and array which we used to maintain topoorder
​
now in the end if size of topoarray is equal to course than no cycle detected
​
​