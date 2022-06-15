class Solution {
    static bool cmp(string &a,string &b)
    {
        return a.size()<b.size();
    }
    bool isPrede(string& a, string& b)
    {
        if (a.size() + 1 != b.size())
            return false;
        int i = 0;
        int j = 0;
        while (i < a.size() and j < b.size()) 
        {
            if (a[i] == b[j])
                i++;
            j++;
        }
        return i == a.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> LIS(n,1);
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                //if jth words is predecessor of ith word and 
                // it can incrase LIS 
                if(isPrede(words[j],words[i]) and LIS[i]<=LIS[j]+1)
                {
                    LIS[i] = LIS[j]+1;
                }   
            }
        }
        return *max_element(LIS.begin(),LIS.end());
    }
};