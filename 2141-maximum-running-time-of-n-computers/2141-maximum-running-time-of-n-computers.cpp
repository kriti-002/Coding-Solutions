class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long sum = accumulate(batteries.begin(), batteries.end(), 0L);
        int k = 0, b = batteries.size();
        while (batteries[b - 1 - k] > sum / (n - k)) sum -= batteries[b - 1 - k++];
        return sum / (n - k);
    }
};