#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define mp make_pair
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(j,a,b) for(int j=a;j>b;j--)
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>


#define trav(a,x) for (auto& a : x)
#define all(x) x.begin(), x.end()

class Solution{
public:
    void solve(){
        ll n,k;cin>>n>>k;
        if(k==0){
            f(i,0,n/2){
                cout<<i<<" "<<(i^(n-1))<<endl;
            }
        }else if(k>0 and k<n-1){
            cout<<k<<" "<<n-1<<endl;
            int l=1,h=n-2;
            while(l<h){
                if(l==k){
                    cout<<0<<" "<<h<<endl;
                }else if(h==k){
                    cout<<0<<" "<<l<<endl;
                }else{
                    cout<<h<<" "<<l<<endl;
                }
                h--;l++;
            }
        }else{
            if(n==4){
                cout<<-1<<endl;return;
            }
            cout<<n-1<<" "<<n-2<<endl;
            cout<<1<<" "<<n-3<<endl;
            cout<<0<<" "<<2<<endl;
            ll l=3,h=n-4;
            while(l<h){
                cout<<l++<<" "<<h--<<endl;
            }
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    Solution ob;
    while(t--){
        ob.solve();
    }
    return 0;
}