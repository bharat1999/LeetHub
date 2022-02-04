class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int prefix=0;
        int maxLen;
        for(int i=0;i<nums.size();i++)
        {
            prefix+= nums[i]==0?-1:1;
            if(prefix==0) // for case like 000111 whole subarray till now is answer
                maxLen=i+1;
            // means current prefix sum is encountered before so the number of elements
            // between that idnex and cur is the answer
            else if(m.count(prefix)>0)
                maxLen=max(maxLen,i-m[prefix]);
            // if not encountered earlier put in map
            else
                m[prefix]=i;
        }
        return maxLen;
    }
};