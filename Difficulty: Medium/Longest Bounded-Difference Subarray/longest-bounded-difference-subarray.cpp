//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        deque<pair<int,int>>maxdq;
        deque<pair<int,int>>mindq;
        maxdq.push_back({arr[0],0});
        mindq.push_back({arr[0],0});
        int currl = 0;
        int currR = 1;
        int ansl = 0;
        int ansr = 0;
        while(currR < n){
            while(!maxdq.empty() && (maxdq.back().first < arr[currR]))
                maxdq.pop_back();
            maxdq.push_back({arr[currR],currR});
            while(!mindq.empty() && mindq.back().first > arr[currR])
                mindq.pop_back();
            mindq.push_back({arr[currR],currR});
            if(abs(maxdq.front().first - mindq.front().first) > x){
                if(maxdq.front().first == arr[currR]){
                    while(maxdq.front().first - mindq.front().first > x){
                        currl = mindq.front().second+1;
                        mindq.pop_front();
                    }
                }
                else{
                    while(maxdq.front().first - mindq.front().first > x){
                        currl = maxdq.front().second+1;
                        maxdq.pop_front();
                    }
                }
            }
            if(currR-currl+1 > ansr-ansl+1){
                ansr = currR;
                ansl = currl;
            }
            currR++;
        }
        vector<int>ans(ansr-ansl+1);
        int ind = 0;
        for(int i=ansl;i<=ansr;i++){
            ans[ind] = arr[i];
            ind++;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends