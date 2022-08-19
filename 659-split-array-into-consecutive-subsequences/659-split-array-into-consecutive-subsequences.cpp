class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        // heap will contain the size of sequences starting from that number
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for(int i = n-1; i >=0; i--)
        {
            int add = nums[i];    
            if(m[add+1].size())
            {
                // add length of smallest sequence starting from add + 1 to add & remove it
                m[add].push(m[add+1].top()+1);
                m[add+1].pop();
            }
            else
            {
                // make new sequence starting from add with length 1
                m[add].push(1);
            }
        }
        

        for(auto i : m)
        {
            // iterating over all subsequence starting from x.first
            while(i.second.size())
            {
                // if any sequence length is less than 3 than pop
                if(i.second.top() < 3) 
                    return false;
                i.second.pop();
            }
        }
        return true;
    }
};