class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> chk(nums.begin(), nums.end());              
        sort(chk.begin(), chk.end());                         
        int n = nums.size(), s = 0, e = n - 1;                
        while (s < n and nums[s] == chk[s])                 
            s++; 
        while (e > s and nums[e] == chk[e])               
            e--;
        return e - s+1;  
        
    }
};