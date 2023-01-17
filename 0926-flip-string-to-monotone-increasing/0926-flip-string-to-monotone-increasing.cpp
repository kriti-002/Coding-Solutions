class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zero = 0, count_one = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') zero++;
            else  count_one++;
            
            zero = min(zero, count_one);
        }
        
        return zero;
    }
};