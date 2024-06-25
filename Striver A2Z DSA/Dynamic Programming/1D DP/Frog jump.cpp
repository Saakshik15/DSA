/*
Problem statement:

 Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. 
 A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is 
 abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by 
 the Geek to jump from stair 0 to stair N-1.

Example:
Input:
n = 4
height = {10 20 30 10}
Output:
20
Explanation:
Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
so, total energy lost is 20 which is the minimum.
*/

/*
Recursive approach:

Suppose, we are at stair n, 
there are two ways to reach stair n, by n-1 and n-2 th stairs respectively.
Now, we want to find the minimum among these two.

Thus, we will have two options, one from say left, which will be n-1 th stair option and
another one from say right, which will be n-2 th stair option.

so,
left= cost+ abs(height[n] - height[n-1])
right= cost+ abs(height[n] - height[n-2])

now, selecting the minimum from these two,
cost = min(left, right)
*/


// Memoization

class Solution {
  public:
    int solve(vector<int>& height, int i, vector<int>& dp){
        if(i==0) return 0;
        if(dp[i] != -1) return dp[i];
        
        int oneStep = solve(height, i-1, dp) + abs(height[i]- height[i-1]);
        int twoStep = (i>1)? solve(height, i-2, dp) + abs(height[i]- height[i-2]): INT_MAX; 
        
        return dp[i] = min(oneStep, twoStep);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, -1);
        return solve(height, n-1, dp);
    }
};


// Tabulation

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
            int oneStep= dp[i-1] + abs(height[i]- height[i-1]);
            int twoStep= (i>1)? dp[i-2]+ abs(height[i]- height[i-2]): INT_MAX;
            
            dp[i]= min(oneStep, twoStep);
        }
        return dp[n-1];
    }
};


// Space optimization

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int prev1=0, prev2=0, curr;
        
        for(int i=1; i<n; i++){
            int oneStep= prev1 + abs(height[i]- height[i-1]);
            int twoStep= (i>1)? prev2 + abs(height[i]- height[i-2]): INT_MAX;
            
            curr = min(oneStep, twoStep);
            prev2= prev1;
            prev1= curr;
        }
        return prev1;
    }
};
