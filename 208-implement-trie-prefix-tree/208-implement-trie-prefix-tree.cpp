class node
{
    unordered_map<char,node*> children;
    public:
        bool isEnd;
        node()
        {
            isEnd = false;
        }
        node* getChild(char ch)
        {
            if(!children.count(ch))
                children[ch] = new node();
            return children[ch];
        }
        bool isChild(char ch)
        {
            return children.count(ch)>0;
        }
};
class Trie {
    node *root;
    
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node *cur = root;
        for(char w:word)
            cur = cur->getChild(w);
        cur->isEnd = true;
    }
    
    bool search(string word) {
        node *cur = root;
        for(char w:word)
        {
            if(cur->isChild(w))
                cur = cur->getChild(w);
            else
                return false;
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        node *cur = root;
        for(char w:prefix)
        {
            if(cur->isChild(w))
                cur = cur->getChild(w);
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */