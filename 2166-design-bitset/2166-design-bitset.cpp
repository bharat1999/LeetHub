class Bitset {
public:
    vector<int> bit;
    int flipcount;
    int bitcount;
    int n;
    Bitset(int size) {
        n=size;
        bitcount = 0;
        flipcount = 0;
        bit.resize(n,0);
    }
    
    void fix(int idx) {
        //flipcount even means bit will be in original state
        if(flipcount%2==0)
        {
            // if current is zero make 1
            if(bit[idx]==0)
            {
                bit[idx]=1;
                bitcount++;
            }
        }
        // flipcount odd means bit will be flipped
        else
        {
            // if its set means after flip it will be unset so make it set in               //final array we will unset it as after flip it will become unset
            if(bit[idx]==1)
            {
                bit[idx]=0;
                bitcount++;
            }
        }
    }
    
    void unfix(int idx) 
    {
        //flipcount even means bit will be in original state
          if(flipcount%2==0)
          {
            // if bit is set unset it
            if(bit[idx]==1){
                bit[idx]=0;
                bitcount--;
            }
        }
        // flipcount odd means bit will be flipped
        else{
            // if its unset means after flip it will be set so make it unset 
            //in final array we will set it as after flip it will become unset
            if(bit[idx]==0){
                bit[idx]=1;
                bitcount--;
            }
        }
    }
    
    void flip() {
        flipcount++;
        bitcount=n-bitcount;
    }
    
    bool all() {
       return bitcount==n;
    }
    
    bool one() {
       return bitcount>=1;
    }
    
    int count() {     
        return bitcount;
    }
    
    string toString() 
    {
        string ans;
        for(auto x:bit)
        {
            // if flip are even bit will be in original state
            // so add as it is
            if(flipcount%2==0)
                ans.push_back(x+'0');
            // if flip are odd means bit will be flipped so flip and add
            else
            {
                if(x==0) 
                    ans.push_back('1');
                else
                    ans.push_back('0');
                }
            }
            return ans;
    }
};