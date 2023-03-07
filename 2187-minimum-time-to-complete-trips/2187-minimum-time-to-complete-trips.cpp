class Solution {
    bool timeNeeded(vector<int>&time, long long x, int totalTrips){
        long long sum=0;
        for(int t: time) sum += x / t;
        return sum >= totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        //sort(time.begin(), time.end());
        long long left = 1, right = (long long)totalTrips * *min_element(time.begin(), time.end());
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (!timeNeeded(time,mid,totalTrips)) left = mid + 1;
        else right = mid;
    }
    return left;
    }
};