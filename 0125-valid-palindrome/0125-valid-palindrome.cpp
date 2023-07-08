class Solution {
    bool isPalin(string tmp){
        int i=0, j=tmp.length()-1;
        while(i<j){
            if(tmp[i++]!= tmp[j--]) return false;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string tmp;
        for(auto c: s){
            if((c>='A' and c<='Z') or (c>='a' and c<='z') or (c>='0' and c<='9')) tmp.push_back(tolower(c));
        }
        return isPalin(tmp);
    }
};