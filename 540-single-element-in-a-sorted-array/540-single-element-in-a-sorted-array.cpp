class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start = 0, end = n - 1, mid;
 
        // For Edge Cases
        if (n == 1) // If only one element is in the array
            return nums[0];
        // If the first element is the element the appears only once 
        if (nums[start]!= nums[start + 1])    
        return nums[start];
 
        // If Last element is the element that appears only once
        if (nums[end]   != nums[end - 1])
            return nums[end];
 
       while (start <= end)
        {
            mid = start + (end - start) / 2;
       
            // base case
            if (nums[mid] != nums[mid - 1] and nums[mid] != nums[mid + 1])
                return nums[mid];
        
           // if mid is even and element at m = m+1 that means left part do not have answer
           // if mid is odd and element at m = m-1 mean left part do not have answer 
            else if ((nums[mid] == nums[mid + 1] and mid % 2 == 0) or 
                     (nums[mid] == nums[mid - 1] and mid % 2 != 0))
                start = mid + 1;
       
            //When mid element is odd and equal to mid+1 element this means number is not present in the right side of the array or
// When mid element is even and equal to mid-1 element this means number is not present in the right side of the array. In this case end pointer will change to mid-1. 
            else
                end = mid - 1;
        }
    return -1;
    }
};