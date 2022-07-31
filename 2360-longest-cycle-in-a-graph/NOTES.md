**Explanation**
​
Here we will use dfs to first get to know if cycle exist and also the longest cycle for that we will maintain a visited array to keep tracked of visited as well as at what count we visit taht w
​
We will have a count and we will assign count to each node when we visit it and oncrment it
​
for example suppose a cycle exist in 1 2 3 and at 1 vi[1] = 0;
vi[2] =1 vi[3]=2 now when we again reach 1 it is already visited so lenth is count that 3 - vis[1] = 3-0 = 3