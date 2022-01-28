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
    Node* root = NULL;
    bool search(Node* root,string &s, int i) 
    {
        // If we checked whole string check if cur node is an ending point of word or not
        if(i == s.size()) 
            return root->isEnd;
        // If current character is not . check if cur node have ch as child or not
        // is its their recursively search by going to ch node and next char of string to be
        // searched if not return false
        if(s[i]!= '.') 
        {    
            if(root -> hasChild(s[i])) 
                return search(root -> gotoChild(s[i]), s, i + 1);
            else
                return false;
        }
        // If current character is . than check for all possible children node of current node
        // Set ans to false initially and OR it with every possible answer if any one if true
        // Our answer will be true
        // So we will search in child node of current with index i + 1
        bool ans = false;
        for(auto &itr : root -> children) 
            ans |= search(itr.second, s, i + 1);
        return ans;
    }
    
public:
    Trie() 
    {
       root = new Node(); 
    }
    void insert(string &s) 
    {    
        auto cur = root;
        for(auto &ch : s) 
            cur  = cur->gotoChild(ch);
        cur -> isEnd = true;
    }
    bool search(string &s) 
    {
        return search(root, s, 0);
    }
};


class WordDictionary {
    Trie t;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.search(word);
    }
    
};