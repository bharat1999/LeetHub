class Solution {
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto x:words)
        {
            string t ="";
            for(auto y:x)
                t+=morse[y-'a'];
            st.insert(t);
        }
        return st.size();
    }
};