class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int no=0; no < (1<<n); no++) 
        {// for each no, iterate over its n-bit binary representation from right to left
            vector<int> tmp;
		    for(int i=0; i<n; i++) 
            {
			    // if the ith bit of no is set, include the element at the ith index in the subseq.
			    if((1<<i)&no)
                    tmp.push_back(nums[i]);
			}
		    ans.push_back(tmp);
	    }
        return ans;
    }
};