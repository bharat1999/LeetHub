class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int , int>> st; //we make a stack to store elements in monotonic decreasing order and also store minimum value
        int currMin = nums[0]; 
        for(int i=1;i<nums.size();i++) // traversing the given vector from index 1 as index 0 is already concidered in currMin 
        {
            while(!st.empty() and nums[i]>=st.top().first) // keep removing all greater and equal elements because we need k=less than j
                st.pop();
            if(!st.empty() and nums[i]>st.top().second) // and if the stack still non-empty this means that our current element is less 
			//than the top of the stack ( jth element ) , So now we check if this element is greater than the minimum value(ith) in the stack
                return true;
            st.push({nums[i],currMin}); // push current element and previous minimum
            currMin = min(currMin,nums[i]); // update the minimum element
        }
        return false; 
    }
};