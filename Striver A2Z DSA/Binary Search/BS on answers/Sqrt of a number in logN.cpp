/*
Problem Statement: You are given a positive integer n. Your task is to find and return its square root. 
If ‘n’ is not a perfect square, then return the floor value of ‘sqrt(n)’.
*/

/*
Solution :

Approach : brute force approach 

We can guarantee that our answer will lie between the range from 1 to n i.e. the given number. 
So, we will perform a linear search on this range and we will find the maximum number x, such that x*x <= n.
*/

//pseudo-code for brute force approach :

for(int i=1 to n) { 
    if(i*i <=n) ans = i;
    else break;
}

/*
Approach 2 : optimal approach using binary search

Initialize the pointers low = 1 and high = n
now, mid = (low+high) / 2
Eliminating the halves: 
1.If mid*mid <= n: ‘mid’ is the possible answer. So, we will store ‘mid’ in the variable ‘ans’. 
  But as we want the maximum number, so we will eliminate the left half and consider the right half(i.e. low = mid+1).
2.mid is larger. Thus numbers greater than mid will not be answers and 
  we will eliminate the right half and consider the left half(i.e. high = mid-1).
Finally, the ans variable will be answer. Additionally high pointer will point to the same number.
*/

//code :

int ans=1, low=1, high=n;

while(low<=high) {

  long long mid = (low+high) / 2;

  if(mid*mid <= n) {
    ans = mid;
    low = mid+1;
  }
  else 
    high= mid-1;
}
return ans;

//time complexity : O(logN)
//space complexity : O(1)

/*
Approach 3 : In built C++ library function 
*/

C++ function : sqrt(n);








