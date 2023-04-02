class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        int sp=s.size(), po=p.size();
        vector<int> v(sp,0);
        sort(p.begin(),p.end());
        
        for(int i=0;i<sp;i++){
            int h=po-1, l=0;
            int mid;
            while(l<=h){
                mid=l + (h-l)/2;
                if((long long)s[i]*(long long)p[mid] >= success)
                    h = mid-1;
                
                else
                    l = mid+1;
            }
            v[i] = po-1-h;
        }
        
        return v;
    }
};