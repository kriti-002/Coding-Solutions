class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>m;
        for(int i=0; i<order.length(); i++){
            m[order[i]]=i;
        }
        for(int i=1; i<words.size();i++){
            int x= words[i-1].length(), y=words[i].length();
            int j=0;
            for(j; j<min(x,y); j++){
                if(words[i-1][j]!=words[i][j]){
                    if(m[words[i-1][j]] >m[words[i][j]]){
                        return false;
                    }else{
                        break;
                    }
                }
            }
            if(j==y and x>y) return false;
        }
        return true;
    }
};