class Node 
{    
    public:
        unordered_map<char,Node*> children;
        bool isEnd;
        Node()
        {
            isEnd = false;
        }
        // Helper function to create a child node if not present and goto it
        Node* gotoChild(char ch) 
        {
            if(children.count(ch) == 0)
                children[ch] = new Node();
            return children[ch];
        }
        // Helper function to check if ch is child of current node or not
        bool hasChild(char ch) {
            return children.count(ch) > 0;
        }
};

class Trie 
{    
    Node* root;
public:
    Trie() 
    {
       root = new Node(); 
    }
    void insert(string &word) 
    {    
        auto cur = root;
        int n = word.size();
        for(int i=n-1;i>=0;i--) 
            cur  = cur->gotoChild(word[i]);
        cur -> isEnd = true;
    }
    void dfsHelper(Node* cur,unordered_set<Node*> &visited,int &totalLen,int len,int &words)
    {
        if(visited.find(cur)!=visited.end())
            return;
        //mark as visited
        visited.insert(cur);
        // we are at leaf node
        if(cur->children.size()==0)
        {
            totalLen+=len;
            words++;
            return;
        }
        for(auto x:cur->children)
            dfsHelper(x.second,visited,totalLen,len+1,words);
    }
    int dfs()
    {
        int len = 0;
        int totalLen =0;
        int words = 0;
        unordered_set<Node*> visited;
        dfsHelper(root,visited,totalLen,len,words);
        return totalLen + words;
    }
};



class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie t;
        sort(words.begin(),words.end());
        for(auto word:words)
        {
            t.insert(word);
        }
        auto ans = t.dfs();
        return ans;
    }
};