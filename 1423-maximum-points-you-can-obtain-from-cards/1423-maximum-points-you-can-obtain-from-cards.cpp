class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int totalSum = accumulate(a.begin(),a.end(),0);
        int n = a.size();
        int win = n-k;
        //calculating first window
        int sum=0;
        for(int i=0;i<win;i++)
            sum+=a[i];
        int minSum = sum;
        //calculating next windows
        for(int i=win;i<n;i++)
        {
            sum = sum-a[i-win]+a[i];
            minSum=min(minSum,sum);
        }
        return totalSum - minSum;
    }
};