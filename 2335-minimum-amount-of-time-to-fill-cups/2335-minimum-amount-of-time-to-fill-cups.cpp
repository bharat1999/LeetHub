class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto x:amount)
        {
            if(x!=0)
                pq.push(x);
        }
        int sec = 0;
        if(pq.size()==0)
            return 0;
        while(pq.size()>1)
        {
            int f1 = pq.top();
            pq.pop();
            int f2 = pq.top();
            pq.pop();
            cout<<f1<<" "<<f2<<" "<<pq.size()<<endl;
            sec++;
            f1--;
            f2--;
            if(f1!=0)
                pq.push(f1);
            if(f2!=0)
                pq.push(f2);
        }
        if(pq.size()==0)
            return sec;
        sec+=pq.top();
        return sec;
    }
};