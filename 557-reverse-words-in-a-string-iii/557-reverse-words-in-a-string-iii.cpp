class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string ans="";
        while(ss)
        {
            string tmp;
            ss>>tmp;
            reverse(tmp.begin(),tmp.end());
            ans+=tmp+" ";
        }
        return ans.substr(0,ans.size()-2);
        
    }
};