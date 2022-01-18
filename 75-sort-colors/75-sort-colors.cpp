class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int i=0;// to iterate over array
        int n=nums.size();
        int low=0; // index for inserting one's // from begin
        int high=n-1; // index for inserting two's from end
        while (i <= high)
        {
            if (nums[i] == 0) // place it at position of lo
                swap(nums[i++], nums[low++]);
            else if (nums[i] == 2) // place it at end
                swap(nums[i], nums[high--]);
            else // do nothing
                i++;
        }
    }   
};