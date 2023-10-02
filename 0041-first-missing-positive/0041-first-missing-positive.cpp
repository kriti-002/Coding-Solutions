class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n,0);
        for (int &x:nums)
        {
            if(x>n or x<1) continue;
            a[x-1]=x;
        }
        
        for(int i=0;i<n;i++)
        {
            if(!a[i]) return i+1;
        }
        return n+1;
    }
};