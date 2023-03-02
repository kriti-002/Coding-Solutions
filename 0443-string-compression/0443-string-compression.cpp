class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n<=1) return n;
        
        char curr = chars[0];
        int count = 1;
        string s;
        for (int i = 1; i <=n; i++) {
            if (i < n && chars[i] == curr) {
                count++;
            } else {
                s.push_back(curr);
                if (count > 1) {
                    string str = to_string(count);
                    for (char c : str) {
                        s.push_back(c);
                    }
                }
                curr = i < n ? chars[i] : 0;
                count = 1;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};