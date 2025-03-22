//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr,int i,bool isPicked, vector<vector<int>>&dp){
        if(i < 0)
            return 0;
        int inc = 0;
        int skip = 0;
        if(dp[i][isPicked] != -1)
            return dp[i][isPicked];
        if(i == 0 && !isPicked){
            inc = arr[i] + solve(arr,i-2,isPicked,dp);
        }
        if(i != 0){
            if(i == arr.size()-1)
                inc = arr[i] + solve(arr,i-2,true,dp);
            else
                inc = arr[i] + solve(arr,i-2,isPicked,dp);
        }
        skip = solve(arr,i-1,isPicked,dp);
        return dp[i][isPicked] = max(inc,skip);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        vector<vector<int>>dp(arr.size(),vector<int>(2,-1));
        return solve(arr,arr.size()-1,false,dp);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends