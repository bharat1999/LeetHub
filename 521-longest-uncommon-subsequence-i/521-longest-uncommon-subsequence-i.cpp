class Solution {
public:
    int findLUSlength(string a, string b) {
        // if both are equal than -1
        if(a==b)
            return -1;
        // otherwise the large string is the ans bcz that will not be equal
        // for exam ab and abc answer will be 3 and subsequence abd is not in ab
        return max(a.size(),b.size());
            
    }
};