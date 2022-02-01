class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e = nums.size()-1;
        while(s<=e)
        {
            int mid = e - (e-s)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[s]<=nums[mid]) // means left part is sorted
            {
                // means target lie in sorted part so seacrh in it
                if(nums[s]<=target and target<=nums[mid]) 
                    e = mid-1;
                // go to unsorted part
                else
                    s = mid +1;
            }
            else // means right part is sorted
            {
                // means target lie in sorted part
                if(nums[mid]<=target and target<=nums[e])
                    s = mid + 1;
                //go to unsorted part
                else
                    e = mid - 1;
            }
        }
        return -1;
        
    }
};