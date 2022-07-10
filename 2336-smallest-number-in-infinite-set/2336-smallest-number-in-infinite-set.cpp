class SmallestInfiniteSet {
    int smallest;
    unordered_set<int> deleted;
public:
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        while(deleted.count(smallest))
            smallest++;
        deleted.insert(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        deleted.erase(num);
        if(num<=smallest)
            smallest = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */