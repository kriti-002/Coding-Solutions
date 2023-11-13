class Solution {
public:
    bool isVowel(char c){
        if(c=='a' or c=='A' or c=='e' or c=='E' or c=='i' or c=='I' or c=='o' or c=='O' or c=='u' or c=='U') return true;
        return false;
    }
    
    string sortVowels(string s) {
        string v, res;
        vector<int> pos;
        for(int i=0; i<s.length(); i++){
            if(isVowel(s[i])){
                v.push_back(s[i]);
                pos.push_back(i);
            }
        }
        sort(v.begin(), v.end());
        res=s;
        for(int i=0; i<pos.size(); i++) res[pos[i]]=v[i];
        return res;
    }
};