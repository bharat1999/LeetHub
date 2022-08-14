class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> path;
    unordered_map<string, int> depth;
    // Step 2 : We will dfs back from endword to begin to avoid unnecessary DFS calls
    void dfs(string cur,string &bw) 
    {
        path.push_back(cur);
        if (cur == bw)
        {
            vector<string> temp = path;
            // reverse cause we are doing reverse dfs
            reverse(temp.begin(),temp.end());
            // add to ans
            ans.push_back(temp);
            path.pop_back();
            return;
        }
        int curDepth = depth[cur];
        string v = cur;
        for (int i = 0; i < cur.size(); i++)
        {
            char c = v[i];
            for (char a = 'a'; a <= 'z'; a++)
            {
                v[i] = a;
                // if we have new word word in list its just one level ahead of current dfs on it
                if (depth.count(v) and depth[v] == curDepth - 1)
                    dfs(v,bw);
            }
            // backtrack to original
            v[i] = c;
        }
        path.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord)==dict.end())
            return ans;
        queue<string> q;
        q.push(beginWord);
        depth[beginWord] = 0;
        // Step 1 finding shortest path
        while (!q.empty())  
        {
            int n = q.size();
            while (n--)
            {
                string u = q.front();
                q.pop();
                int x = depth[u] + 1;
                for (int i = 0,s=u.size(); i < s; i++)
                {
                    string v = u;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        v[i] = ch;
                        // if depth of new word not calculated and word avl in list update depth and add to queue
                        if (!depth.count(v) and dict.count(v))
                            depth[v] = x, q.push(v);
                    }
                }
            }
        }
        dfs(endWord,beginWord);
        return ans;
    }
};