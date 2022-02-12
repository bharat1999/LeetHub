class Solution {
    public:
    int ladderLength(string beginWord, string endWord, vector<string>&wordList) 
    {
        unordered_set<string> words(wordList.begin(),wordList.end());
        // if endWord not present in dictionary
        if(words.find(endWord)==words.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        // Ans = 1 as one tranformation is always required
        int ans = 1;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string u = q.front();
                q.pop();
                if(u==endWord)
                    return ans;
                string v = u;
                // To avoid going back to same
                words.erase(u);
                for(int i=0,s=u.size();i<s;i++)
                {
                    char temp = v[i];
                    for(char c='a';c<='z';c++)
                    {
                        v[i]=c;
                        if(words.find(v)!=words.end())
                        {
                            q.push(v);
                            // Delete from set so that it will not repeat
                            words.erase(v);
                        }
                    }
                    // change back to original character
                    v[i]=temp;
                }
            }
            ans++;
        }
        // If notfound after visiting all nodes return 0;
        return 0;
    }
};