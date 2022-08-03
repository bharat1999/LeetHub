class MyCalendar {
    map<int,int> cal;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(cal.size()==0)
        {
            cal[start] = end;
            return true;
        }
        auto it = cal.lower_bound(start);
        if(it!=cal.end() and it->first<end)
            return false;
        if(it!=cal.begin())
        {
            it--;
            if(it->second>start)
                return false;
        }
        cal[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */