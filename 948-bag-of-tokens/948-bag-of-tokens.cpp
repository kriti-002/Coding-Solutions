class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        if(tokens.size()==0 or power <tokens[0]) return 0;
        int l=0, r=tokens.size()-1, res=0, score=0;
        while(l<=r){
            if(power >= tokens[l]){
                power-=tokens[l];
                score++;
                l++;
                res=max(res, score);
            }else if(r-l >1){
                score--;
                power+=tokens[r];
                r--;
            }else{
                break;
            }
        }
        return res;
    }
};