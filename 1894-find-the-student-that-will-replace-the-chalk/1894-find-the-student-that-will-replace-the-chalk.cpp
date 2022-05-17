class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> prefix(n);
        prefix[0]=chalk[0];
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + chalk[i];
        // if k>sum than it all chalk can be subtracted multiple itmes
        k%= prefix.back();
        int l=0,r=chalk.size()-1;
        // now we will search for last index less than k
        while(l<r)
        {
            int mid = (l+r)/2;
            if(prefix[mid]>k)
            {
                r = mid;
            }
            else 
                l=mid+1;
        }
        return l;
    }
};