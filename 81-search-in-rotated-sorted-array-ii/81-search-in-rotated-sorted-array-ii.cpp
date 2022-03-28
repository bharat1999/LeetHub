class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        while(s<=e)
        {
            int mid = e -(e-s)/2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[s] == nums[mid]) && (nums[e] == nums[mid]))
            {
                s++;
                e--;
            }
			// first half is sorted
            else if(nums[s] <= nums[mid])
            {
				// target is in sorted part
                if((nums[s] <= target) && (nums[mid] > target))
                    e = mid - 1;
                // target in unsorted part
                else
                    s = mid + 1;
            }
			// second half is sorted
            else
            {
                // target in sorted part
                if((nums[mid] < target) && (nums[e]>= target))
                    s = mid + 1;
                // target in unsorted
                else
                    e = mid - 1;
            }
        }
        return false;
    }
};