class Solution {
public:
    string countAndSay(int n) {
        string s="1";
    if(n==1)
        return s;
    // for n = 2
    s+='1';
    if(n==2)
        return s;
    n-=2;
    while(n--)
    {   
        int i=0;
        string res="";//initialising temperoary result
        while(i<s.size())
        {   
            int c=1;
            //finding freq of current char
            while(s[i]==s[i+1])//finding frequency of the present chracter
            {   
                c++;
                i++;
            }
            // converting frequency to string
            string d=to_string(c);
            // appending freq before the number
            res+=d;
            // adding number to ans
            res+=s[i];
            i++;
        }
        // setting s = res for next iteration
        s=res;
        }
        return s;
    }
};