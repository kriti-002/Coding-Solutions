class Solution {
public:
    string removeStars(string s) {
        string res="";
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='*') st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            char ch= st.top(); st.pop();
            res+=ch;
        }
        if(res != ""){
            reverse(res.begin(), res.end());
            return res;
        }
        return res;
    }
};