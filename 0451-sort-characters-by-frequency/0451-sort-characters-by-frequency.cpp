class Solution {
public:
    string frequencySort(string s) {
        map<char, int>m;
        for(auto x: s) m[x]++;
        priority_queue<pair<int, int>>pq;
        for(auto x: m){
            pq.push({x.second,x.first});
        }
        string res="";
        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            res+=string(x.first,x.second);
        }
        return res;
    }
};