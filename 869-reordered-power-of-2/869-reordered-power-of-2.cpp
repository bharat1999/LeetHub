class Solution {
    vector<int> count(long long n)
    {
        vector<int> c(10);
        while(n)
        {
            int r = n%10;
            c[r]++;
            n/=10;
        }
        return c;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> countOfN = count(n);
        for(int i=0;i<31;i++)
        {
            vector<int> countOfPow = count((1<<i));
            if(countOfN==countOfPow)
                return true;
        }
        return false;
    }
};