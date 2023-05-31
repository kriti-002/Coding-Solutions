class UndergroundSystem {
    unordered_map<int, pair<string,int>>mp1;
    unordered_map<string, pair<int,int>>mp2;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp1[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto x=mp1[id];
        mp1.erase(id);
        string route = x.first + "_" + stationName;
        mp2[route].first += t - x.second;
        mp2[route].second += 1; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route  = startStation + "_" + endStation;
        auto time = mp2[route];
        return (double)time.first/time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */