/*
How to approach dp problems:

1. Try to represent the problem in terms of index.
2. Do all possible stuffs on that index according to the problem statement.
3. If the question says:
  count all the ways -> Sum of all stuff
  Mininum of all the stuff -> find minimum 
  maximum of all the stuff -> find maximum
*/


/*
Solving climbing stairs problem:

Treating everything as index: 1, 2, 3, 4, 5, ..........n
f(n) = no of ways.

Now, from that stair, we can jump either 1 or 2 according to the problem statement.

*/

// pseudocode:

fun(n){

  //base case, if we are at stair 1 or 0 there is only one way to climb the stairs.
  if(n==0 || n==1) return 1;

  //left recursive tree + right recursive tree will be two ways to climb the stairs and return the ans.
  return fun(n-1) + fun(n-2);
}


// There are 4 ways to solve this problem:

// 1. Recursive approach (as above)

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;

        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// 2. Memoization (top-down dp)

class Solution {
public:

    int solve(int n, vector<int>& dp){
        if(n==0 || n==1) return 1;

        if(dp[n] != -1) return dp[n];
        return dp[n] = (solve(n-1, dp)+ solve(n-2, dp));
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// 3. Tabulation (bottom-up dp)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        dp[0]=1;
        dp[1]=1;

        for(int i=2; i<=n; i++){
            dp[i]= dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//space optimization

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1 ) return 1;
        
        int prev1=1, prev2=1, curr;

        for(int i=2; i<=n; i++){
            curr= prev1 + prev2;
            prev2= prev1;
            prev1= curr;
        }
        return curr;
    }
};

