class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
	    for (int i = 0; i < numRows; i++) 
        {
            // create row with i+1 elements and initial value 1
		    vector<int> row(i + 1, 1);
            //ser values from 1 index to i-1 index using res 
		    for (int j = 1; j < i; j++) 
			    row[j] = res[i - 1][j] + res[i - 1][j - 1];
		    res.push_back(row);
	}
	return res;
    }
};