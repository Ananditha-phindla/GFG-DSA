//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int sumOfDivisors(int n) {
        // Write Your Code here
        int ans = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=sqrt(i);j++){
                if(j * j == i){
                    ans += j;
                    continue;
                }
                if(i % j == 0){
                    ans += j;
                    if(i/j != j){
                        ans += (i/j);
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends