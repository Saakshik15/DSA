class Solution {
  public:
  
    long long int mod= 1e9+7;
    
    long long int solve(int n, vector<long long int>& dp){
        if(n<=1) return n;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n]= (solve(n-1, dp)+ solve(n-2, dp))%mod;
    }
  
    long long int topDown(int n) {
        vector <long long int> dp(n+1, -1);
        return solve(n, dp);
    }
    
    long long int bottomUp(int n) {
        long long int prev1=1, prev2=0;
        
        for(int i=2; i<=n; i++){
            long long int curr= (prev1+prev2)%mod ;
            prev2= prev1;
            prev1= curr;
        }
        
        return prev1%mod;
    }
};
