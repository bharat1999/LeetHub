**Explanation**
​
We know that for any row r and column c the element will be rCc
​
If we calculate it everytime it will be quadratic , but here we have to calculate it for a series of terms
​
Here indexing is 0 bases
​
For example we have to find terms of 4th row
​
they will be 4C0 = 1 ,4C1 = 4 ,4C2 = 6 , 4C3 = 4 , 4C4 =1
The first and last terms will be always 1 but we can observer something from the middle terms
​
4C1 = 4 * 3 *2 *1 / 3 * 2 * 1 = 1 * 4 / 1
4C2 = 4 * 3 * 2 * 1 / 2 * 1 * 2 * 1 = 4 * 3 / 2
4C3 = 4 * 3 * 2 * 1 / 3 * 2 * 1  = 6 * 2 / 3
​
We can see that each term = prev term  * num / deno
where num start with r and deno start with 1 and num decrease in each step and deno increase in each step
​
​
​
​
​
​
​
​
​