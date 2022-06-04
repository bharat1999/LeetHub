class Solution {
    bool isValid(string &s)
    {
        if(s.size()==1)
            return false;
        if(s[0]!='$')
            return false;
        for(int i=1,n=s.size();i<n;i++)
            if(!isdigit(s[i]))
                return false;
        return true;
    }
public:
    string discountPrices(string sentence, int discount) {
        stringstream s(sentence);
        string ans ="";
        string word;
        while(s>>word)
        {
            if(!isValid(word))
                ans+=word+" ";
            else
            {
                long long no=0;
                for(int i=1,n=word.size();i<n;i++)
                    no=no*10+ word[i]-'0';
                double answer = double(no) - (double(no)*discount/100);
                string tmp = "$";
                answer=round(answer*100)/100;
                stringstream stream;
                stream << fixed << setprecision(2) << answer;
                string answerStr = stream.str();
                tmp+=answerStr+" ";
                ans+=tmp;
            }
        }
        ans.pop_back();
        return ans;
    }
};