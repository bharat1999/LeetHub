class Solution {
    vector<int> tmp;
public:
    int merge(vector<int>& nums, int start, int mid, int end){
        
        int p = start;
        int q = mid + 1;
        int ans = 0;
        
        while(p <= mid){
            while(q <= end && (long long)nums[p] <= (long long)2 * nums[q]){
                q++;
            }
            ans += end + 1 - q;
            p++;
        }
        
        p = start;
        q = mid + 1;
        int r = start;
        
        while(p <= mid && q <= end){
            if(nums[p] >= nums[q]){
                tmp[r++] = nums[p++];
            }
            else{
                tmp[r++] = nums[q++];
            }
        }
        
        while(p <= mid){
            tmp[r++] = nums[p++];
        }
        
        while(q <= end){
            tmp[r++] = nums[q++];
        }
        
        for(int i = start; i <= end; i++){
            nums[i] = tmp[i];
        }
        return ans;
    }
    
    int mergeSort(vector<int>& nums, int start, int end){
        if(start == end){
            return 0;
        }
        int mid = start + (end - start) / 2;
        int left = mergeSort(nums, start, mid);
        int right = mergeSort(nums, mid + 1, end);
        int center = merge(nums, start, mid, end);
        return left + right + center;
    }
    
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        tmp.resize(len);
        return mergeSort(nums, 0, len - 1);
    }
};