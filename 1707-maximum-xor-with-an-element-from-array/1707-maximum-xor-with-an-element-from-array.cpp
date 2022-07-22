class Node{
    public:
    Node* bits[2];
    
    bool hasChild(int bit)
    {
        return bits[bit]!=NULL;
    }
    
    Node* getChild(int bit)
    {
        if(!hasChild(bit))
            bits[bit] = new Node();
        return bits[bit];
    }
};
class Trie{
  private: Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(int num)
    {
        Node* node=root;
        
        for(int i=31;i>=0;--i)
        {
            int bit=(num&(1<<i))?1:0;
            node=node->getChild(bit);
        }
    }
    
    int getmax(int num)
    {
        Node* node=root;
        int mx=0;
        for(int i=31;i>=0;--i)
        {
            int curBit = num&(1<<i)?1:0;
            int reqBit = curBit^1;
            
            if(node->hasChild(reqBit))
            {
                mx+=(1<<i);
                node=node->getChild(reqBit);
            }
            else
                node=node->getChild(curBit);
        }
        return mx;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans(queries.size(),0);
        vector<pair<int,pair<int,int>>> vp;
        for(int i=0;i<queries.size();++i)
            vp.push_back({queries[i][1],{queries[i][0],i}});
        sort(vp.begin(),vp.end());
        Trie t;
        int i = 0;
        // O(Q * 32 + N * 32)
        for(auto &it: vp){
            int ai = it.first;
            int xi = it.second.first;
            int index = it.second.second;
            while(i < nums.size() and nums[i] <= ai){
                t.insert(nums[i]);
                i++;
            }
            if(i != 0)
                ans[index] = t.getmax(xi);
            else
                ans[index] = -1;
        }
        return ans;
    }
};