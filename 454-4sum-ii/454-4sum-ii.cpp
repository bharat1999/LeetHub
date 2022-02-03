class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mp[nums3[i]+nums4[j]]++;
        int c=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)    
            {
                int tmp = -(nums1[i]+nums2[j]);
                if(mp.count(tmp)>0)
                    c+=mp[tmp];
            }
        return c;
    }
};