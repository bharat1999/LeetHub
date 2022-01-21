Here we iterate from right to left and check if we can can reach the last index = n-1 from the current index or not if we can reach last from current index we update last to that inxed because now we have to reach the new last index from current index
​
ex     2 3 1 1 4
idx= 0 1 2 3 4
​
last = 4
curr i =3 so 3+1 >=4 that mean we can reach last from cur index so now last = 3;
​
cur i =2 , 2+1>=3 that mean we can reach 3 index from w so now update last =2
​
cur i=1 , 1+3 >=2 means we can reach 2 from 1 so update last =1
​
cur i =0 , 0 + 2 >=1 means we can reach 1 from 0 so last =0 ;
​
now our loop ends now we check is our last is 0 or not becuase we have to start from 0
​
if it is true our answer is true otherwise false
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
​
​