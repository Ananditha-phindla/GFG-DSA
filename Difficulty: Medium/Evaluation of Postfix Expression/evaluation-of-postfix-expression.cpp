//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(auto i : arr){
            if((i == "+") || i == "-" || i == "*" || i == "/"){
                int f = st.top();
                st.pop();
                int s = st.top();
                st.pop();
                if(i == "+")
                    st.push(s+f);
                else if(i == "-")
                    st.push(s-f);
                else if(i == "*")
                    st.push(s*f);
                else
                    st.push(s/f);
            }
            else{
                int val = stoi(i);
                st.push(val);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends