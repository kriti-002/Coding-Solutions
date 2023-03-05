class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n ==1) return 0;
        unordered_map<int, vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        vector<bool>vis(n, 0);
        q.push(0); vis[0]=1;
        int res=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto x= q.front(); q.pop();
                if(x==n-1) return res;
                vector<int>& vec= mp[arr[x]];
                vec.push_back(x-1); vec.push_back(x+1);
                for(auto nextIdx : vec){
                    if(nextIdx >=0 and nextIdx<n and !vis[nextIdx]){
                        q.push(nextIdx);
                        vis[nextIdx]=1;
                    }
                }
                vec.clear();
            }
            res++;
        }
        return -1;
    }
};