#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define mp make_pair
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(j,a,b) for(int j=a;j>b;j--)
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<string,int>


#define trav(a,x) for (auto& a : x)
#define all(x) x.begin(), x.end()

class Solution{
public:
    void solve(){
        int n,k;cin>>n>>k;
        vector<pi> a(n);f(i,0,n){
            string t;cin>>t;
            a[i].first = t;
            a[i].second = i+1;
        }
        sort(all(a),[](pi a,pi b){
            if(a.first==b.first){
                return a.first<b.first;
            }
            int l=0,r=0;
            string s = a.first,t = b.first;
            while(l<s.size() and r<t.size() and s[l]==t[r]){l++;r++;}
            if(l&1){
                return a.first>b.first;
            }
            return a.first<b.first;
        });
        trav(i,a){
            cout<<i.second<<" ";
        }
        cout<<endl;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin>>t;
    Solution ob;
    while(t--){
        ob.solve();
    }
    return 0;
}