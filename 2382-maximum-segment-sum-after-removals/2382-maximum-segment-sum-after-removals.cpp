class Solution {
public:

struct dsu {

    vector<int> p;
    vector<long long> sum;
    int n;
    dsu(int _n = -1) {if (_n >= 0) init(_n);}

    void init(int _n) {p.assign(_n + 1, -1); n = _n;sum.assign(n+1,0LL);}
    int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool unite(int x, int y) {
        x = find(x),y = find(y),sum[x] += sum[y],p[y] = x;
        return true;
    }
    long long  getsum(int x){return sum[find(x)];}
};

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& qr) {
        vector<long long> ans;      
        int n=  qr.size();
        long long cur=0;
        ans.push_back(cur);
        reverse(qr.begin(),qr.end());
        qr.pop_back();
        dsu tr=dsu(n);
        for(int &x:qr)
        {
            tr.p[x]=x;
            tr.sum[x]=nums[x];
            if(x+1<n && tr.p[x+1]>x){
                tr.sum[x]+=tr.sum[x+1];
                tr.p[x+1]=x;
            }            
            if(x>0 && tr.p[x-1]>=0)tr.unite(x-1,x);

            cur=max(cur,tr.getsum(x));
            ans.push_back(cur);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};