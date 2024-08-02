/*
This is a follow up question for frog jump.
In frog jump, we could jump 1 step or 2 steps at a time, but in this follow up, we can jump till k steps at a time.
Now, this k might vary for each test case, so the method of solving this problem changes.
*/

/*
Since k is given and no definite number for jumps is given, we can convert it into a for loop where value for k jumps would be calculated.


*/


// Memoization: top-down

int solve(int n, vector<int>& arr, int k, vector<int>& dp){
  //base case: cost to reach the first stone is 0
  if(n==0) return 0;

  //use memoized result if it is calculated
  if(dp[n] != -1) return dp[n];

  int mini= INT_MAX;
  for(int i=1; i<=k; i++){
    //to verify that jump is not a negative index
    if(n-i >= 0){
      int jump= solve(n-i, arr, k, dp) + abs(arr[n] - arr[n-i]);
      mini= min(mini, jump);
    }
  }
  return dp[n]= mini; //memoize the result
}

int minimizeCost(vector<int>& arr, int k){
  int n= arr.size();
  vector<int> dp(n, -1);

  return solve(n-1, arr, k, dp);
}

