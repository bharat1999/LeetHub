class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size(),i=0,ans=0;
         while(i<n)
         {
              int s=i;
              while(s<n && nums[s]==0)
                  s++;
              int e=s;
              int sn=-1,en=-1,c=0;
              while(e<n && nums[e]!=0){
                  if(nums[e]<0){
                      if(sn==-1)sn=e;
                      en=e;
                      c++;
                  }
                  e++;
              }
              if(c%2==0)
                  ans=max(ans,e-s);
              else
                  ans=max(max(e-sn-1,en-s),ans);
              i=e+1;
          }
          return ans;
    }
};