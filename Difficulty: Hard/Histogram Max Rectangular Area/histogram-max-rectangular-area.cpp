//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int ans = 0;
        int n = arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i])
                st.pop();
            left[i] = st.top();
            st.push(i);
        }
        
        while(st.top() != -1)
            st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i])
                st.pop();
            if(st.top() == -1)
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i]-left[i]-1)*arr[i]);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends