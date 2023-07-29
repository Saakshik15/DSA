/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

/*
Approach : recursive approach

In recursive approach, we will make use of this logic in maths :

2^10 = ((2)^2^)5 = (2*2)^5 = (4^5)

4^5 = 4 * 4^4

4^4 = ((4^2)^2) = (4*4)^2 = 16^2

16^2 = (16*16)^1

256^1 = 256 * 256^0

and then pass the ans 256 to the prev calculations to get the ans.

here, we may conclude that 
when (n%2 == 0) -> (x*x)^ (n/2)
when (n%2 == 1) -> ans= (x* ans) ; n= n-1
when n==0 stop(base case)
*/

//code :

double myPow(double x, int n) {
        double ans= 1.0;
        long long nn= n;
        if(nn<0) nn= -1*nn;

        while(nn){
            if(nn%2){
                ans= ans*x;
                nn= nn-1;
            }else{
                x= x*x;
                nn= nn/2;
            }
        }
        if(n<0) ans= (double)(1.0)/ (double)(ans);
        return ans;
    }

//time complexity : O(logN)
//space complexity : O(N)
