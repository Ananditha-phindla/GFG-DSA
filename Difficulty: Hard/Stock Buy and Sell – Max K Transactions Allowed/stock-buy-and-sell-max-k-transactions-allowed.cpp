//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int solve(vector<int>& prices, int k,int i,bool isBuy, vector<vector<vector<int>>>&dp){
        if(k <= 0 || i >= prices.size())
            return 0;
        int inc = 0;
        int skip = 0;
        if(dp[i][k][isBuy] != -1)
            return dp[i][k][isBuy];
        if(isBuy){
            inc = prices[i] + solve(prices,k-1,i+1,false,dp);
            skip = solve(prices,k,i+1,isBuy,dp);
        }
        else{
            inc = -prices[i] + solve(prices,k,i+1,true,dp);
            skip = solve(prices,k,i+1,isBuy,dp);
        }
        return dp[i][k][isBuy] = max(inc,skip);
    }
    
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(prices,k,0,false,dp);
    }
};




//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends