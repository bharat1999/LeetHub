class NumberContainers {
    unordered_map<int,int> idxToVal;
    unordered_map<int,set<int>> valToIdx;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // if no element at this index
        if(idxToVal.count(index)==0)
        {
            idxToVal[index] = number;
            valToIdx[number].insert(index);
        }
        else
        {
            int prev = idxToVal[index];
            // remove index of previous form valToIdx
            valToIdx[prev].erase(valToIdx[prev].find(index));
            //update in idxToVal and valToIdx
            idxToVal[index] = number;
            valToIdx[number].insert(index);
        }
            
    }
    
    int find(int number) {
        if(valToIdx[number].size()==0)
            return -1;
        return *valToIdx[number].begin();
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */