class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int x=minutesToTest/minutesToDie;
        return ceil(log10(buckets)/ log10(x+1));
    }
};