**Explanation**
​
O(n ^ 2)
We are asked to break a positive integer n into 2 or more integers with maximum product. To find the optimal breakdown, as we know each breakdown divides the original problem into sub-problems, we can use DP  to store  the results of sub-problems.
​
Assume f[i] means the maximum product we can get to breakdown i (i <= n).
Starting point: f[1] = 1
Transition equation:
​
we will recursively go from n to 0
for each n we will calculate answer as
​
for(int i =1;i<n;i++)
ans = max(ans, max(f(n-i) *i , (n-i) * i)
because the answer will be either the product of n divided in two parts as i and n-i or
the answer for the subproblem where n = n-i;
​
Some notes:
​
The equation looks like a product of two numbers, how does it cover the cases that i is divided into more than 2 intergers? ---> the two factors in the multiplication can be f[j] and f[i - j], these two can further break down to a product of multiple integers
Why do we have j as one of the possible factors as in max(j, f[j])? ---> As per above equation, f[j] will be the product of at least two numbers, but in some cases, j itself can be bigger than all the possible product of its breakdowns, for example, when j == 2, f[j] == 1, j is greater than f[j].