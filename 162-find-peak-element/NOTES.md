**Asked in Amazon**
​
It is tricky as its one of rare question using binary search in unsorted array
​
As, the subportions of the array are increasing/decreasing ( only then we would be able to find peak ), there are subportions of array which are sorted, so we could use binary search to get this problem done. But exactly how ?
​
As O(logn) is asked we have to use binary search somehow?.
Let's us find out how
As, the subportions of the array are increasing/decreasing ( only then we would be able to find peak ), there are subportions of array which are sorted, so we could use binary search to get this problem done.
​
For a mid element, there could be three possible cases :
​
​
Case 1 : mid lies on the right of our result peak ( Observation : Our peak element search space is leftside )
Case 2 : mid is equal to the peak element ( Observation : mid element is greater than its neighbors )
Case 3 : mid lies on the left. ( Observation : Our peak element search space is rightside )
​
So whenever we find a mid we check for above three conditions and find the answer
​
​
​
​
​
so, the code becomes