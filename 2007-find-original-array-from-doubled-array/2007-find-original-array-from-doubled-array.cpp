class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n&1) return {};
        
        unordered_map<int, int>m;
        for(auto &data : changed) m[data]++;
        
        sort(changed.begin(), changed.end());
        vector<int> res;
        changed.erase(unique(changed.begin(), changed.end()), changed.end()); // remove ocuurence of same number in consecutive manner
        
        for(auto x: changed){
            if(m[x] > m[x*2]) return {};
            for(int i=0; i<m[x]; i++){
              res.push_back(x);
              m[x*2]--;  
            }
            
        }
        return res;
    }
};