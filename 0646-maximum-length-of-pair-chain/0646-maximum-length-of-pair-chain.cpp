class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [&] (auto a, auto b) {return a[1] < b[1];});
        int chain=1, prev= pairs[0][1];
        for(int i=1; i<pairs.size(); i++){
                if(prev < pairs[i][0]){
                    chain++;
                    prev=pairs[i][1];
                } 
        }
        return chain;
    }
};