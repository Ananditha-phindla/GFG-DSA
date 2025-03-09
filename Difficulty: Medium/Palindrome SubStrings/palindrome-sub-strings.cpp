//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.length();
        int ans = 0;
        unordered_set<int>myset;
        for(int i=0;i<n;i++){
            int p1 = i,p2 = i;
            while(p1 >= 0 && p2 <= n && s[p1] == s[p2]){
                ans++;
                p1--;
                p2++;
            }
            p1 = i,p2 = i+1;
            while(p1 >= 0 && p2 <= n && s[p1] == s[p2]){
                ans++;
                p1--;
                p2++;
            }
        }
        return ans - n;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends