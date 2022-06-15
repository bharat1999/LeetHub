**Explanation**
​
It is somewhat similar to LIS , we just have to make a function which tell us if the current word can be predecessor of next
​
**Another Approach
​
We canalso use a map to store the max chain length for each word we got
​
for example a , ba, bca
we start with a and chain lenght =1
we can only delete 1 from a and check in map if dp[""]+1>dp["a"]
​
now for ba initial length= 1
now we delete b and we are left with a so chain lenght of a is 1 so answer is 1+1 =2
if we delete a we are left with b and we do not have b in dp
​
now for bca we delete b but we dont have ca in map
than delete ca now we have ba in dp which is 2 to answer is 2+1 =3 ;