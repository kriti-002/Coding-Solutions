class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>vec(numRows, "");
        if(numRows== 1) return s;
        int dir=1, row=0, n=s.length();
        for(int i=0; i<n; i++){
            vec[row]+=s[i];
            if(row== numRows-1) dir=-1;
            if(row==0) dir=1;
            row+=dir;
        }
        string res="";
        for(auto x: vec) res+=x;
        return res;
    }
};