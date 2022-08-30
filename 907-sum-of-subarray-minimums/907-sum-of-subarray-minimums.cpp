class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> left_bound(n);
        vector<int> right_bound(n);
        stack<int> left;
        stack<int> right;
        for(int i = 0; i < n; i++)
        {
            // getting index of element smaller than arr[i]
            while(!left.empty() && arr[left.top()] > arr[i]) 
                left.pop();
            // if stack empty mean no smaller than x
            // that mean all to left are greater
            if(left.empty()) 
                left_bound[i] = 0;
            // otherwise elements till smaller +1 index are greater than arr[i]
            else 
                left_bound[i] = left.top() + 1;
            left.push(i);
        }
        
        for(int i = n - 1; i >= 0; i--){
            while(!right.empty() && arr[right.top()] >= arr[i]) 
                right.pop();
            // if st empty mea all to right of arr[i] are greater 
            if(right.empty()) 
                right_bound[i] = n - 1;
            else 
                right_bound[i] = right.top() - 1;
            right.push(i);
        }
        
        for(int i = 0; i < n; i++)
        {
            // greater ele to left = n 
            // greater to right = m
            // than subarray having arr[i] as min will be (n+1)*(m+1)
            // so add arr[i] count times in sum
            long long count = (i - left_bound[i] + 1) * (right_bound[i] - i + 1);
            sum = (sum + (arr[i] * count % mod) % mod) % mod;
        }
         
        return sum % mod;
    }
};