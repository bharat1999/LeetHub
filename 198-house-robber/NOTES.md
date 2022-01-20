**Explanation**
​
Here we have two choices either loot current house or not
If we loot current house we have to skip next house
If we skip current house we can loot the next house
​
so f(i) = max(nums[i]+f(i+2),f(i+1))
​
here their are overlapping sub problems so we optimise by lookup table