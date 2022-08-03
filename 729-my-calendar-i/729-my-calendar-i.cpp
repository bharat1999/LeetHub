class MyCalendar {
    vector<pair<int,int>> cal;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(cal.size()==0)
        {
            cal.push_back({start,end});
            return true;
        }
        for(auto x:cal)
        {
            if(x.first>=end or x.second<=start)
                continue;
            else 
                return false;
        }
        cal.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */