**Explanation**
​
The brute force approach of this is very simple run two loops and check for all possible pairs. But it will give TLE
​
So what can help us here
For that we need to think in bits and know how xor works
​
So to get max xor of two number if we have a number whose decimal representation is
101 so the number which give max xor with it will be 010 but this will not always be available in the array . So what we need to do is that for we have to check for every number we cannot skip that but to check the max possible xor of that number , we need to check the number which is similar to the best number , and to do that optimally we will use a Trie because in try searching similar terms is almost constant
​
so we will insert all number in our tri starting from the most significant bit and than search for the most best answer.
​
​
​
​
​
​
​
​
​
​