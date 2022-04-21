class MyHashSet {
    vector<int> hash;
public:
    MyHashSet() {
        hash.resize(1000001,-1);
    }
    
    void add(int key) {
        hash[key]=key;
    }
    
    void remove(int key) {
        hash[key]=-1;

    }
    
    bool contains(int key) {
        return hash[key]==key;

    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */