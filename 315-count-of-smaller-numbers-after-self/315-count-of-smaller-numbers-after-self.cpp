class Solution {
    vector<int> count;
    vector<pair<int,int>> temp;
public:

    void merge(int left, int mid, int right, vector<pair<int, int>>& arr)
    {        
        int i = left;
        int j = mid + 1;
        int k = left;
        
        while(i <= mid and j <= right)
        {
            // putting in descending order so we can calculate right smaller easily
            if(arr[i].first <= arr[j].first)
                temp[k++] = arr[j++]; 
            // as j<i so all right to j will be small
            // so ans is r  - j +1
            else
            {
                count[arr[i].second] += (right - j +1);
                temp[k++] = arr[i++];
            }
        }
        
        while(i <= mid)
            temp[k++] = arr[i++];
        
        while(j <= right)
            temp[k++] = arr[j++];
        
        for(int l = left; l <= right; l++)
            arr[l] = temp[l];
        
    }
                
    void mergeSort(int left, int right, vector<pair<int, int>>& arr)
    {
        if(left >= right)
            return;

        int mid = left + (right - left) / 2;
        
        mergeSort(left, mid, arr);
        mergeSort(mid + 1, right, arr);
        
        merge(left, mid, right, arr);
    }
    
	vector<int> countSmaller(vector<int>& nums) {
	    
        int n=nums.size();
        count.resize(n);
        temp.resize(n);
	    vector<pair<int, int>> arr;
	    for(int i = 0; i < n; i++)
	        arr.push_back({nums[i], i});
	    mergeSort(0, n - 1, arr);
	    return count;
	}
  
};