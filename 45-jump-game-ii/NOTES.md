Here we will keep track of the **currReach** which is the current farthest reached position we can have using the , **farthestReach** which is the max possible position we can reach from current index and the number of jumps;
​
whenever we reach the currReach we increase the jump signfying that we have completed the current level in terms of BFS and than we update the currReach = farthtestReach because that is now the max position we can reach
​
​
​
​
Ex   2 3 1 1 4
idx  0 1 2 3 4
​
Initially jump =0 , farthest =0 , currReach =0
​
Iteration i=0
​
farthest = max(0,2+0) = 2
i==currReach
means we have reached the max position from current level
currReach = 2, jumps =1
​
Iteration i = 1
farthest=max(2,1+3) = 4;
​
i!=currReach so we can reach this from the current level no need to jump
​
Iteration i = 2
farthest = max(4,2+1) = 4
​
i== means we have reached the max position from current level
currReach = 4, jumps =2
​
Iteration i = 3
farthest = max(4,3+1) = 4
i!=currReach so we can reach this from the current level no need to jump
​
Iteration i =4
​
farthest = max(4,4+4) = 8
​
i==currReach
means we have reached the farthest we can go from the current level so now we increase the level that is jump and make currReach = farthest that is the next max reachable position
​
so we increase jump , jump =2;
currReach = 8;
​
our loop ends and jump = 2 is the minimum jump required
​
​