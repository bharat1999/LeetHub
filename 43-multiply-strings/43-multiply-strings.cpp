class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        // making ans string of max size so that we can fill from right to left
        vector<int> res(num1.size()+num2.size(), 0);
        
        for (int i = num1.size()-1; i >= 0; i--) 
        {
            for (int j = num2.size()-1; j >= 0; j--) 
            {
                res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
                // adding carryover if any to prev cell
                res[i + j] += res[i + j + 1] / 10;
                // removing 10th place digit if any
                res[i + j + 1] %= 10;
            }
        }
        
        int i = 0;
        string ans = "";
        // removing leading zeroes
        while (res[i] == 0) 
            i++;
        while (i < res.size()) 
            ans += to_string(res[i++]);
        return ans;
    }
};