class SummaryRanges {
public:
    set<int>val;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        val.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(val.empty()) return {};
        vector<vector<int>>intervals;
        int l=-1, r=-1;
        for(int x: val){
            if(l<0) l=r=x;
            else if(x == r +1) r=x;
            else{
                intervals.push_back({l,r});
                l=r=x;
            }
        }
        intervals.push_back({l,r});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */