


class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26);
        for(auto x:s)
            freq[x-'a']++;
        sort(freq.begin(),freq.end(),greater<int>());
        int ans = 0;
        int lastFreq=freq[0]+1;
        for(int i=0;i<26 and freq[i]>0;i++)
        {
            // if fre is not permissible make it permissible and update
            if(freq[i]>=lastFreq)
            {
                ans+=freq[i]-lastFreq;
                freq[i] = lastFreq;
            }
            lastFreq=max(0,freq[i]-1);
        }
        return ans;
        
    }
};