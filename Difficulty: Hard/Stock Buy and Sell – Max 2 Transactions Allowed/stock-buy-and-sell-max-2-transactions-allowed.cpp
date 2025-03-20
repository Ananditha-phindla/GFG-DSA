//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int> &prices,int k,int i,bool buyed,vector<vector<vector<int>>>&dp){
        if(k == 0 || i >= prices.size())
            return 0;
        int inc = 0;
        int skip =0;
        if(dp[i][k][buyed] != -1)
            return dp[i][k][buyed];
        if(buyed){
            inc = prices[i] + solve(prices,k-1,i+1,false,dp);
            skip = solve(prices,k,i+1,buyed,dp);
        }
        else{
            inc = - prices[i] + solve(prices,k,i+1,true,dp);
            skip = solve(prices,k,i+1,buyed,dp);
        }
        return dp[i][k][buyed] = max(inc,skip);
        
    }
    int maxProfit(vector<int> &prices) {
        // code here
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2+1,vector<int>(2,-1)));
        return solve(prices,2,0,false,dp);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends