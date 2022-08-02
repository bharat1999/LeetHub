class Solution {
    int countLessOrEqual(vector<vector<int>>& matrix, int x,int n) 
    {
        int cnt = 0, c = n - 1; 
        for (int r = 0; r < n; ++r) {
            while (c >= 0 && matrix[r][c] > x) --c;  
            cnt += (c + 1);
        }
        return cnt;
    }
    public:
 int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); 
        int left = matrix[0][0], right = matrix[n-1][n-1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid,n) >= k) {
                ans = mid;
                right = mid - 1; // try to looking for a smaller value in the left side
            } else left = mid + 1; // try to looking for a bigger value in the right side
        }
        return ans;
    }
    
};