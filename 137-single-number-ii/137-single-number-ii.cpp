class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int bitSum=0;
            for(int x:nums){
                bitSum+=(1&(x>>i));
            }
            if(bitSum%3){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};