class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto x:magazine)
            mp[x]++;
        for(int i=0,n=ransomNote.size();i<n;i++)
        {
            if(mp[ransomNote[i]]==0)
                return false;
            else
                mp[ransomNote[i]]--;
        }
        return true;
    }
};