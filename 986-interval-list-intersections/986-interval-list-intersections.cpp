class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int n = A.size();
        int m = B.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m )
        {
            int start1 = A[i][0];
            int end1 = A[i][1];
            int start2 = B[j][0];
            int end2 = B[j][1];
			// intersection condition
            if(end1 >= start2 && start1 <= end2) 
                ans.push_back({max(start1, start2), min(end1, end2)});
            // increment pointer of list whose interval ended first
            end1 < end2 ? i++ : j++;    
        }
        return ans;
    }
};