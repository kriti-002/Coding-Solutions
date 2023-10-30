class Solution {
public:
    static bool comp(int a,int b){
        if(__builtin_popcount(a) < __builtin_popcount(b))
            return true;
        if(__builtin_popcount(a) == __builtin_popcount(b))
            return a<b;
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        stable_sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};