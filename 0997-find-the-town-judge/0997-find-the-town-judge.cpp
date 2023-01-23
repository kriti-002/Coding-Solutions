class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustedBy(n+1);
        vector<int>trusted(n+1);
        for(int i=0; i<trust.size(); i++){
            trustedBy[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++){
            if(trustedBy[i]==0 and trusted[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};