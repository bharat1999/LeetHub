class node {
    public:
	    vector<node*> children;
	    int count;
        node()
        {
            children.resize(26,NULL);
            count = 0;
        }
        node* getChild(char ch)
        {
            if(!children[ch-'a'])
                children[ch-'a'] = new node();
            return children[ch-'a'];
        }
        
};

class Solution {
	node *root = new node();
public:

	// For inserting the string into Trie
	void insert(string s)
	{
		auto cur = root;
		for(auto i:s)
		{
            // Check that if current char present in the Trie,if not helper function will make it
			cur = cur->getChild(i);
            //increment count for that
            cur->count++;
		}
	}

	int countPrefix(string s)
	{
		auto cur = root;
		int cnt = 0;
		for(auto i:s)
		{
            cur = cur->getChild(i);
			cnt+= cur->count;
		}
		return cnt;
	}

	vector<int> sumPrefixScores(vector<string>& words) {

		int n = words.size();
		vector<int> ans(n);
        // add all words in Trie
		for(auto i:words)
			insert(i);

		for(int i=0;i<n;i++)
			ans[i] = countPrefix(words[i]);
		return ans;
	}
};