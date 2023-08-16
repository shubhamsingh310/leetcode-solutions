//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int findCatalan(int n) 
    {
        
    if (n==1 || n==0){
        return 1;
    }
    
    int mod = 1e9+7;
    
    vector<long long int> ans(n+1,0);
    
    ans[0] = 1;
    ans[1] = 1;
    
    for(int i = 2; i<=n; i++){
        int l=0; int r = i-1;
        
        while(l<i && r>=0){
            ans[i] = (ans[i] + (ans[l]*ans[r])%mod)%mod;
            l++;
            r--;
        }
    } 
        return ans[n];
     
    }
};


//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends