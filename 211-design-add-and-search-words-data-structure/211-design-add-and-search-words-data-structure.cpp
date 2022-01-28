class Trie
{
    public:
    bool isEnd;
    unordered_map<char,Trie*> mp;
    Trie()
    {
        isEnd = false;
    }
};

class WordDictionary 
{
    Trie *root = new Trie();
    bool search(string s,Trie *root)
    {
        auto *cur = root;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            if(c!='.')
            {
                if(cur->mp.count(c)==0)
                    return false;
                else
                    cur = cur->mp[c];
            }
            else
            {
                if(cur->mp.empty())
                    return false;
                for(auto x:cur->mp)
                {
                    cur = x.second;
                    if(search(s.substr(i+1),cur))
                        return true;
                }
            }
        }
        return cur->isEnd;
    }   
public:
    
    WordDictionary() {
        
    }
    
    void addWord(string word) 
    {
        auto *cur = root;
        for(auto c:word)
        {
            if(cur->mp.count(c)==0)
                cur->mp[c] = new Trie();
            cur = cur->mp[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return search(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */