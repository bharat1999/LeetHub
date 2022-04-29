**Explanation**
​
Based on graph coloring if we can color the graph such that color of child is not equal to parent than its can be bipartite also the node in one set should not be connected to other of smae set ,  so we can do bfs or dfs on each uncolored node and color each node if any node mathc color with parent return false