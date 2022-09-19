class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>>mp;
        for(auto x: paths){
            stringstream ss(x);
            string dir;
            string file;
            getline(ss, dir, ' ');
            while (getline(ss, file, ' ')) {
                string content = file.substr(file.find('(') + 1, file.find(')') - file.find('(') - 1);
                string name = dir + '/' + file.substr(0, file.find('('));
                mp[content].push_back(name);
            }
        }
        vector<vector<string>>res;
        for(auto x: mp){
            if(x.second.size() >=2) res.push_back(x.second);
        }
        return res;
    }
};