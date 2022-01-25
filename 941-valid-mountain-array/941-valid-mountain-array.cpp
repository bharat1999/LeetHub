class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return false;
        int s = 0;
        int e = arr.size()-1;
        while(s<n-1 and arr[s]<arr[s+1])
            s++;
        while(e>0 and arr[e-1]>arr[e])
            e--;
        if(s==n-1 or e==0) // whole arrary is increasing or decreasing
            return false;
        if(e==s)
            return true;
        return false;
        
    }
};