class Solution {
public:
    int bestClosingTime(string s) {
        int j = -1, score = 0, maxScore = 0;
        for (int i = 0; i < s.size(); ++i) {
            score += (s[i] == 'Y') ? 1 : -1;
            if (score > maxScore) {
                j = i;
                maxScore = score;
            }
        }
        
        return j + 1;
    }
};