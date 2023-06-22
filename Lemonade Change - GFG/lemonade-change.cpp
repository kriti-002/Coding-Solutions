//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int count5 = 0,count10 = 0,count20 = 0;
        for(int i = 0;i<N;i++){
            if(bills[i] == 5) count5++;
            else if(bills[i] == 10){
                if(count5<=0) return 0;
                count5--;
                count10++;
            }else{
                if(count5<=0) return 0;
                if(count10>0){
                    count10--;
                    count5--;
                }else if(count5 >= 3) count5-=3;
                else return 0;
                count20++;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends