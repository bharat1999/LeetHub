class UndergroundSystem {
    unordered_map<int,pair<string,int>> checkedIn;
    map<pair<string,string>,vector<int>> times;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        if(checkedIn.find(id)!=checkedIn.end())
            return;
        checkedIn[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        
        times[{checkedIn[id].first,stationName}].push_back(t-checkedIn[id].second);
        checkedIn.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> t = times[{startStation,endStation}];
        int sum = accumulate(t.begin(),t.end(),0);
        return double(sum)/t.size();

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */