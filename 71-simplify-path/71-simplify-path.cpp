class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;
        for(int i=0,n=path.size();i<n;i++)
        {
            string temp="";
            if(path[i]=='/')
                continue;
            // add to current path temp
            while(i<n and path[i]!='/')
            {
                temp+=path[i];
                i++;
            }
            // if . do nothing
            if(temp==".")
                continue;
            // mean go one directory up
            if(temp=="..")
            {
                // if we have some path remove it
                if(!paths.empty())
                    paths.pop();
            }
            // push current path to paths
            else
                paths.push(temp);
        }
        if(paths.empty())
            return "/";
        string ans="";
        while(!paths.empty())
        {
            ans="/"+paths.top()+ans;
            paths.pop();
        }
        return ans;
    }
};