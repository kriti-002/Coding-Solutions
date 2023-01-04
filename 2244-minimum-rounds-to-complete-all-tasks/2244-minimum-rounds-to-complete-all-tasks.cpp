class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        for(auto x: tasks) m[x]++;
        
        int res=0;
        for(auto x: m){
            if(x.second <2) return -1;
            else if(x.second%3==0) res+=(x.second/3);
            else res+=(x.second/3 + 1);
        }
        return res;
        
    }
};