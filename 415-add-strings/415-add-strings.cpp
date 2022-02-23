class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0,sum;
        int n1 = num1.size();
        int n2 = num2.size();
        string ans;
        int i = n1-1;
        int j = n2-1;
        while(i>=0 and j>=0)
        {
            sum = (num1[i]-'0'+num2[j]-'0'+carry)%10;
            carry = (num1[i]-'0'+num2[j]-'0'+carry)/10;
            ans.push_back(sum+'0');
            i--;
            j--;
        }
        while(i>=0)
        {
            sum = (num1[i]-'0'+carry)%10;
            carry = (num1[i]-'0'+carry)/10;
            ans.push_back(sum+'0');
            i--;
        }
        while(j>=0)
        {
            sum = (num2[j]-'0'+carry)%10;
            carry = (num2[j]-'0'+carry)/10;
            ans.push_back(sum+'0');
            j--;
        }
        if(carry)
            ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};