class Solution {
    vector<string> combo={"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
    void help(int i,string digits, string &tmp, vector<string>&res){
        if(i==digits.size()){
            res.push_back(tmp);
            return;
        }
        string t= combo[digits[i]-'0'];
        for(int j=0; j<t.size(); j++){
            tmp.push_back(t[j]);
            help(i+1, digits, tmp, res);
            tmp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        vector<string>res;
        string tmp;
        help(0,digits, tmp, res);
        return res;
    }
};