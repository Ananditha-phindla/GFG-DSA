//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int W,vector<int> &val, vector<int> &wt,int i,int curr_wt,vector<vector<int>>&dp){
        if(i >= val.size() || curr_wt >= W)
            return 0;
        if(dp[i][curr_wt] != -1)
            return dp[i][curr_wt];
        if(curr_wt + wt[i] > W)
            return dp[i][curr_wt] = solve(W,val,wt,i+1,curr_wt,dp);
         return dp[i][curr_wt] = max(val[i] + solve(W,val,wt,i+1,curr_wt+wt[i],dp),solve(W,val,wt,i+1,curr_wt,dp));
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(W,-1));
        return solve(W,val,wt,0,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends