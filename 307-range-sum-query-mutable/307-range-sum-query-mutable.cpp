class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    int LSB(int a){
        return a & ~(a-1);
    }

    int prefixSum(int i){
        int sum = 0;
        while(i != 0){
            sum += tree[i];
            i -= i & ~(i-1);
        }
        return sum;
    }

    void add(int i, int x){
        while(i < tree.size()){
            tree[i] += x;
            i += i & ~(i-1);
        }
    }
    
    NumArray(vector<int>& arr) {
        nums = arr;
        tree.resize(nums.size() + 1, 0);
        int sum = 0;
        for(int i = 1; i <= nums.size(); i++){
            sum += nums[i-1];
            int j = i;
            tree[i] = sum;
            while(j){
                j = j - (j & ~(j-1));
                tree[i] -= tree[j];
            }
        }
    }
    
    void update(int index, int val) {
        int a = val - nums[index];
        add(index+1, a);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right+1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */