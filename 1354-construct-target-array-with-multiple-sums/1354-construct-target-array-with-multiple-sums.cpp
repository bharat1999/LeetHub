class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> maxHeap(target.begin(),target.end());
        long long sum = 0;
        for(int x:target)
            sum+=x;
        while(maxHeap.top()!=1)
        {
            int greatest = maxHeap.top();
            maxHeap.pop();
            sum-=greatest;
            if(sum==0 or sum>=greatest)
                return false;
            int old = greatest%sum;
            if(sum!=1 and old==0)
                return false;
            maxHeap.push(old);
            sum+=old;
        }
        return 1;
        
    }
};