class Solution {
public:
    double average(vector<int>& salary) {
        double res=0;
        int n=salary.size();
        sort(salary.begin(), salary.end());
        for(int i=1; i<n-1;i++){
            res+=salary[i];
        }
        double av=n-2;
        return res/av;
    }
};