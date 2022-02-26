class Solution {
public:
     vector<int> partitionLabels(string S) {
        vector<int> charIdx(26, 0);
        // calculating the last index of each char
        for(int i = 0; i < S.size(); i++)
            charIdx[S[i]-'a'] = i;
        
        vector<int> results;
        
        // maxIdx to get the lasr index where a char occurence ends
        int maxIdx = -1, lastIdx = 0;
        for(int i = 0; i < S.size(); i++)
        {
            maxIdx = max(maxIdx, charIdx[S[i]-'a']);
            // if current idx is max index means we got a partition 
            if(i == maxIdx) {
                //lenght of partition is the maxindex - lastindex +1
                results.push_back(maxIdx - lastIdx + 1);
                // updating last index as new partition will start from i+1
                lastIdx = i+1;
            }
        }
        return results;
    }
};