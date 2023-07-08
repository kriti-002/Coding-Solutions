class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1, firstchar=0, res=0;
        while(i>=0){
            if(s[i]==' ' and firstchar) break;
            if(s[i]!=' '){
                firstchar=1;
                res++;
                i--;
            }else i--;
        }
        return res;
    }
};