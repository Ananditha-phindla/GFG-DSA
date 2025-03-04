//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int BS(vector<int>&Lis,int val){
        int low = 0;
        int high = Lis.size()-1;
        int ans = Lis.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(Lis[mid] < val)
                low = mid + 1;
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
    
    int lis(vector<int>& arr) {
        // code here
        vector<int>Lis;
        Lis.push_back(INT_MIN);
        for(auto i : arr){
            int idx = BS(Lis,i);
            if(idx == Lis.size())
                Lis.push_back(i);
            else
                Lis[idx] = i;
        }
        return Lis.size()-1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends