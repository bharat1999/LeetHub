class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int ans = 0;
        vector<pair<int,int>> jobs;
        
        for(int i = 0; i < profit.size(); i++) 
        {
            jobs.push_back({profit[i], difficulty[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(), worker.end());
        //sorting both arrays
        int j = profit.size()-1;
        for(int i= worker.size()-1; i >= 0; i--) 
        {
            while(j >= 0 and jobs[j].second > worker[i]) {
                j--;
            }
            if(j < 0) break;
            ans = ans+jobs[j].first;
            
        }
        return ans;
    }
};