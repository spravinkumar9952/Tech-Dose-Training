class UndergroundSystem {
public:
    unordered_map<int, string> mpChkSta;
    unordered_map<int, int> mpChkTime;
    unordered_map<string , double> mpDur;
    unordered_map<string , double> mpTime;
        
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mpChkSta[id] = stationName;
        mpChkTime[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string checkInStation = mpChkSta[id];
        double duration = t - mpChkTime[id];
        mpDur[checkInStation+" "+stationName] += duration;
        mpTime[checkInStation+" "+stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return mpDur[startStation+" "+endStation]/mpTime[startStation+" "+endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */