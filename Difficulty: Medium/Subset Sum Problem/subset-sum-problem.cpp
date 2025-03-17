//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int idx, vector<vector<int>>& dp){
        if(sum < 0)
            return false;
        if(sum == 0)
            return true;
        if(idx < 0)
            return false;
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        return dp[idx][sum] = (solve(arr,sum,idx-1,dp) || solve(arr,sum-arr[idx],idx-1,dp));
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(arr,sum,n-1,dp);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends