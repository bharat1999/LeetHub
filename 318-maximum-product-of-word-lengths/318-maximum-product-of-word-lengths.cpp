class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>> freq(n,vector<bool> (26,false));
        for(int i=0;i<n;i++)
        {
            for(auto x:words[i])
                freq[i][x-'a']=true;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool pos=true;
                if(i==j)
                    continue;
                for(auto x:words[j])
                {
                    // if ith word have same char
                    if(freq[i][x-'a'])
                    {
                        pos = false;
                        break;
                    }
                }
                if(pos)
                { 
                    int t = words[i].size()*words[j].size();
                    ans = max(ans,t);
                }
            }
        }
        return ans;
    }
};