class Solution {
public:
       int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (int &x : nums)
            s.insert(x % 2 ?x * 2 : x);
        int ans = *s.rbegin() - *s.begin();
        // while largest element is even
        while (*s.rbegin() % 2 == 0) 
        {
            // Divide max by 2 and erase current max
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            //Calculate new deviation and take mix
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        return ans;
    }
};