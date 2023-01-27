class Solution {
    bool isConcat(string word, set<string>&st){
        for(int i=1; i<word.length(); i++){
            string prefix= word.substr(0, i);
            string suffix= word.substr(i,word.length()-i);
            if(st.find(prefix)!= st.end() and (st.find(suffix)!= st.end() or isConcat(suffix, st))) return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string>st(words.begin(), words.end());
        vector<string> res;
        for(auto x: words){
            if(isConcat(x, st)){
                res.push_back(x);
            }
        }
        return res;
    }
};