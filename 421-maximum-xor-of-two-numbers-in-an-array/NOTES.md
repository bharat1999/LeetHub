1. We will take a cur pointer and set it to root initially.
2. Than we will iterate from 30 to 0 and check if the ith bit of number is set of not
3. Than we will check if cur already have pointer to that calculated bit or not , if its not insert new node at bits[bit]  and move to next bit , if its already present their is no need to check so move to next bit.
​
After inserting each number in Trie we will find the current max answer for that we will have an ans variable initially set to 0 .
​
Than we will find current MaxXOR using a function by passing current number into it
​
1. We initially set a cur pointer to root of the Trie and & we initialize ans = 0.
2. Than we start iterating from the MSB bit to 0 that is 30 to 0.
3. Than we will check if current bit is set or not and calculate a required_bit = 1^bit.
This is the bit that if avalaible give 1 at current bit otherwise 0.
3.To check that we will check if cur pointer have a not NULL child with required bit or not ,if its their we will add 1<<i means 2^i to the answer and move to required bit child of current otherwise we move to bit child of cur
​
Than we will return the ans , we will do this for all the array elements.
​
I have commented codes and broke it into function for easy understanding
​
Time Complexity : O(n32)  n = nums.size() 32 = Because Trie search in O(length of word) and here all the number have 32 bits.
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