class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto x:paths)
        {
            stringstream s(x);
            string word;
            string path;
            int i = 0;
            s>>word;
            path = word;
            while(s>>word)
            {
                string t = word;    
                bool dataFound = false;
                string fileName = "";
                string fileData = "";
                for(int i = 0;i<t.size();i++)
                {
                    if(t[i]=='(')
                        dataFound = true;
                    if(t[i]==')')
                        break;
                    if(!dataFound)
                        fileName.push_back(t[i]);
                    else if(dataFound)
                        fileData.push_back(t[i]);
                }
                mp[fileData].push_back(path+"/"+fileName);
            }
        }
        for(auto x:mp)
        {
            if(x.second.size()>1)
                ans.push_back(x.second);
        }
        return ans;
    }
};