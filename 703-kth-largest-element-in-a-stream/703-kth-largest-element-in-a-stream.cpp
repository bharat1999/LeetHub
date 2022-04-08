class KthLargest {
    priority_queue<int,vector<int>,greater<int>> hp;
    int t;
public:
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        t=k;
        int i = nums.size()-1;
        while(i>=0 and k)
        {
            hp.push(nums[i]);
            i--;
            k--;
        }
    }
    
    int add(int val) {
        if(hp.size()<t)
            hp.push(val);
        else if(val>hp.top())
        {
            hp.pop();
            hp.push(val);
        }
        return hp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */