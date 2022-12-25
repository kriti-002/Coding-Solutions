class Solution {
public:
    void help(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ help(v, str+")", n, m-1); }
        if(n > 0){ help(v, str+"(", n-1, m+1); }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        help(res, "", n, 0);
        return res;
    }
};