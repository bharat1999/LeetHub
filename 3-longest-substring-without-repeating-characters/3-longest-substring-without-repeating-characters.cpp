class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int window_len=0;
        int max_window_len=0;
        int i=0; // keep track of starting index of current window
        int j=0; // keep track of ending idnex of current window
        unordered_map<char,int> m;
        while(j<s.length())
        {
            char ch=s[j];
            //check if the character is encountered before and its index>=start of window(this means its part of current window)
            if(m.count(ch) and m[ch]>=i)
            {
                //start a new window from last occurance of the character+1
                i=m[ch]+1;
                window_len=j-i; // 1 will be increased every time
            }
            //if new unique character then push character and its occurance in the map
            m[ch]=j;
            window_len++;
            j++;
            max_window_len=max(max_window_len,window_len);
        }
        return max_window_len;
    }
};