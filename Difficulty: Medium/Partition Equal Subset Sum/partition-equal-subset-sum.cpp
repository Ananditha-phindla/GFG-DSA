//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector<int>& arr, int idx, int tsum, int csum, vector<vector<int>>& dp){
        if(csum == tsum)
            return true;
        if(idx < 0 || tsum < 0)
            return false;
        if(dp[idx][tsum] != -1)
            return dp[idx][tsum];
        return dp[idx][tsum] = (solve(arr,idx-1,tsum-arr[idx],csum+arr[idx],dp) ||  solve(arr,idx-1,tsum,csum,dp));
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int tsum  = accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>> dp(n,vector<int>(tsum+1,-1));
        return solve(arr,n-1,tsum,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends