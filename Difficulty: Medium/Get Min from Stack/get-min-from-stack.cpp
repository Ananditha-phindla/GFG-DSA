//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int>st;
    set<int>myset;
    Solution() {
        while(!st.empty())
            st.pop();
        myset.clear();
        // code here
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        st.push(x);
        myset.insert(x);
        // code here
    }

    // Remove the top element from the Stack
    void pop() {
        if(!st.empty()){
            int x = st.top();
            if(myset.count(x))
                myset.erase(x);
            st.pop();
        }
        // code here
    }

    // Returns top element of the Stack
    int peek() {
        if(!st.empty()){
            return st.top();
        }
        return -1;
        // code here
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st.empty()){
            return *myset.begin();
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends