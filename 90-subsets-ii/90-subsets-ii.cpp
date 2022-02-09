class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<string> present;
        for(int no=0; no < (1<<n); no++) 
        {// for each no, iterate over its n-bit binary representation from right to left
            vector<int> tmp;
            string curSubset="";
		    for(int i=0; i<n; i++) 
            {
			    // if the ith bit of no is set,and that nums is not already in answer include the element at the ith index in the subseq.
			    if((1<<i)&no)
                {
                    curSubset+=to_string(nums[i]+',');
                    tmp.push_back(nums[i]);
                }
            }
            // current subset is not in answer than add
            if(present.count(curSubset)==0)
            {
                present.insert(curSubset);
		        ans.push_back(tmp);
            }   
	    }   
        return ans;
    }
};