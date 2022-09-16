class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string res="";
        for(char x: s){
            if(x=='('){
                count++ ? res+="(" : res+=""; 
            }else{
                --count ? res+=")": res+="";
            }
        }
        return res;
    }
};