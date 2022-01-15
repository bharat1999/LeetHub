class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        map<int,int> mp;
        for(int i=0;i<time.size();i++)
        {
            int a=time[i]%60;
            if(a==0) // if it is divisible by 60
                count+=mp[0]; //answer will be count of those number which are divisible by 60 
            else
                count+=mp[60-a]; // else we need to get the number with remainder 60-a so
            // that thier sum become divisible by 60
            mp[a]++; // add frequency of remainder in answer
        }
        return count;
    }
};