class Solution {
    set<int> ans;
    void solve(int l,string no,int k,int n)
    {
        if(l==n)
        {
            ans.insert(stoi(no));
            return;
        }
        int prev = no[l-1]-'0';
        if(prev-k>=0)
        {
            no.push_back((prev-k)+'0');
            solve(l+1,no,k,n);
            no.pop_back();
        }
        if(prev+k<=9) 
        {
            no.push_back((prev+k)+'0');
            solve(l+1,no,k,n);
            no.pop_back();
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++)
        {
            string no= to_string(i);
            solve(1,no,k,n);
        }
        vector<int> res;
        for(auto x:ans)
            res.push_back(x);
        return res;
    }
};