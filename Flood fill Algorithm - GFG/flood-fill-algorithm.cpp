//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void help(int i, int j, int c,int existing, vector<vector<int>>&image){
        int n=image.size(), m=image[0].size();
        if(i<0 or j<0 or i>=n or j>=m) return;
        if(image[i][j]!= existing) return;
        image[i][j]=c;
        help(i+1, j, c,existing, image);
        help(i-1, j, c,existing, image);
        help(i, j-1, c,existing, image);
        help(i, j+1, c,existing, image);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if(image[sr][sc]==newColor) return image; 
        help(sr, sc, newColor,image[sr][sc], image);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends