//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({startWord, 1});
        st.erase(startWord);
        
        while(!q.empty()){
            auto x=q.front(); q.pop();
            string tmp=x.first; int count=x.second;
            if(tmp== targetWord) return count;
            for(int i=0; i<tmp.length(); i++){
                char originalChar=tmp[i];
                for(char j='a' ; j<='z'; j++){
                    tmp[i]=j;
                    if(st.find(tmp)!= st.end()){
                        st.erase(tmp);
                        q.push({tmp, count + 1});
                    }
                    
                }
                tmp[i]=originalChar;
            }
            
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends