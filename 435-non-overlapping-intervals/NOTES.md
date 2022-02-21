**Explanation**
​
This problem is very similar to the interval scheduling problem. In the interval scheduling problem you are given a list of time meetings (intervals with start and end times) and you have to find the maximum number of meetings you can attend. The solution for this problem involves using a greedy solution.
​
In this greedy solution you sort the input by their ending times and only attend meetings where the current start time is greater than the end time of the previous meeting we attend to avoid overlap. In this problem we can do the same thing:
​
*         First sort the given input by the end value of interval
*         Starting at the second interval check for the invalid condition where the current interval's start value is less than the previous valid interval's end value means they overlap
*          If we find an invalid interval then we increase the number of invalid intervals to remove by 1.
*         Otherwise we will update the prev end
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
​
​
- This requires the program to keep track of the previous valid interval's end time.
- Return the number of invalid intervals removed.