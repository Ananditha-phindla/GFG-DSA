//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool static cmp(const string& a, const string& b) {
    return a.size() < b.size();
}

    int longestStringChain(vector<string>& words) {
        // Code here
       sort(words.begin(),words.end(),cmp);
       unordered_map<string,int>dp;
       int ans = 1;
       for(auto word : words){
           dp[word] = 1;
           for(int i=0;i<word.length();i++){
               string temp = word.substr(0,i) + word.substr(i+1);
               if(dp.count(temp)){
                   dp[word] = max(dp[temp]+1,dp[word]);
               }
           }
           ans = max(ans,dp[word]);
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends