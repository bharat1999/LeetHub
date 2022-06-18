class node
{
    public:
        unordered_map<char,node*> children; 
        int idx;
        node()
        {
            idx=-1;
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
    Trie(vector<string> words) {
        root = new node();
        int n = words.size();
        // from end bcz is same string than largest index will be found first
        for(int i=0;i<n;i++)
        {
            string word = "#" + words[i];
            for(int m=words[i].size(),j=m-1;j>=0;j--)
            {
                // means words = #apple it will add make word as e#apple
                // than we get l so it become le#apple
                word = words[i][j]+word;
                // insert in trie with index i
                insert(word,i);
            }
            cout<<endl;
        }
    }
    
    void insert(string word,int i) {
        node *cur = root;
        for(char w:word)
            cur = cur->getChild(w);
        cur->idx = i;
    }
    
    int search(string word) {
        node *cur = root;
        for(char w:word)
        {
            if(cur->isChild(w))
            {
                cur = cur->getChild(w);
            }
            else
                return -1;
        }
        // if we reach here it mean we have that word
        // that idx of cur ptr will not be answer bcz is case of e#appple e will hold idx
        // but if search is e#a our cur will be at a
        // so we have to do dfs on a till its children to get max
        return DFS(cur);
    }
    int DFS(node *cur)
    {
        int res = cur->idx;
        for(auto x:cur->children)
        {
            // x.second will have the address of child
            res = max(res,DFS(x.second));
        }
        return res;
    }
};


class WordFilter {
    Trie *t;
public:
    WordFilter(vector<string>& words) {
        t = new Trie(words);
    }
    
    int f(string prefix, string suffix) {
        string toSearch = suffix+"#"+prefix;
        return t->search(toSearch);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */