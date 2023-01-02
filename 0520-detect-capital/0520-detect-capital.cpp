class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap=0;
        for(auto x: word){
            if(isupper(x)) cap++; 
        }
        int w=word.length();
        return w==cap or cap==0 or (cap==1 and isupper(word[0]));
    }
};