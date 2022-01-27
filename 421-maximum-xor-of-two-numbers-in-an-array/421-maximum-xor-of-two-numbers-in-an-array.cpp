class Solution {
    class node
    {
        vector<node*> bits; 
        public:
        // our vector will have only two values as bit can be 0 or 1
        // they will be initially NULL
        node()
        {
            bits.assign(2,NULL); 
        }
        void insert(int bit)
        {    
            bits[bit] = new node();
        }
        // to check if currrent root have a bit below it or not
        bool isValid(int bit)
        {    
            return bits[bit]!=NULL;
        }
        node* getBit(int bit)
        { 
            return bits[bit];
        }
    };
    class Trie{
        node *root = NULL;
        public:
            Trie()
            {
                root = new node();
            }
            void insert(int n)
            {
                node *cur = root;
                // we will start inserting from MSB
                for(int i=30;i>=0;i--)
                {
                    int bit = ((1<<i)&n)?1:0;
                    // if bit is not child or current insert it
                    if(!cur->isValid(bit))
                        cur->insert(bit);
                    // go to next bit 
                    cur = cur->getBit(bit);
                }
            }
            int maxXOR(int n)
            {
                node *cur = root;
                int ans = 0 ;
                for(int i=30;i>=0;i--)
                {
                    int bit = ((1<<i)&n)?1:0;
                    // this is the bit that will give us 1 after xor
                    int required_bit = bit^1;
                    // if it is present add 2^i to answer
                    if(cur->isValid(required_bit))
                    {    
                        ans+=(1<<i);
                        cur = cur->getBit(required_bit);
                    }        
                    // if not present go to available bit
                    else
                        cur = cur->getBit(bit);
                }
                return ans;
            }  
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans = 0;
        for(auto &x:nums)
        {
            t.insert(x);
            ans = max(ans,t.maxXOR(x));
        }
        return ans;
    }
};