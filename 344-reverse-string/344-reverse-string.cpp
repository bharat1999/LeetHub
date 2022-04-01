class Solution {
public:
    void reverseString(vector<char>& a) {
        int s = 0;
        int e = a.size()-1;
        while(s<e)
            swap(a[s++],a[e--]);
    }
};