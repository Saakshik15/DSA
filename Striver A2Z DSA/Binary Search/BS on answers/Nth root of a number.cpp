/*
Problem statement :

Problem Statement: Given two numbers N and M, find the Nth root of M. 
The nth root of a number M is defined as a number X when raised to the power N equals M. 
If the ‘nth root is not an integer, return -1.
*/

/*
Solution :

approach 1 : brute force approach 

We will linearly search for a number which is equal to the Nth root of M
If the multiplication exceeds the number M while performing a linear search we will conclude that 
there is no perfect root to the number and return -1.

*/

//pseudo-code :

for(i=1 to m) {
  if (f(i,n) == m) return i;
  else if(f(i, n) > m) break;
}
return -1;

/*
Approach 2: optimal approach using binary search

We know that the Nth root of a number M will never exceed M.
So, using binary search we can find the appropriate root to the number by eliminating the search spaces accordingly.

first, low=1 and high= M
then we will find a mid = (low+high)/2
we will check if the mid is the Nth root of M by multiplying mid to itself N times and if it is, we will return the mid.
If not, then there are two cases :
1. The multiplication of mid N times is greater than the root to be found
  In this case, we will move the high pointer to mid-1 th index
2. The multiplication of mid N times is lesser than the root to be found
  In this case, we will move the low pointer to mid+1 th index
In case there is no perfect Nth root of M, the high pointer will exceed the low pointer and we will return -1 in this case
*/

//pseudo-code :

NthRootFunction(N, M){
  int low=1, high= M;
  
  while(low<=high) {
    int mid = (low+high)/2;
  
    if(powFunc(mid, N, M)==1) return mid;
    else if(powFunc(mid, N, M)==2) high= mid-1;
    else if(powFunc(mid, N, M)==0) low= mid+1;
  }
  return -1;
}

//the function below performs power operations
//If result is M returns 1
//If result is < M returns 0
//If result is > M returns 2

int powFunc(int mid, int N, int M) {
  long long ans =1;

  for(int i=1; i<=N; i++){
    ans = ans*mid;
    if(ans>M) return 2;
  }
  if (ans==M) return 1;
  else return 0;
}

//Time complexity : O(logM) * O(N) 
//time complexity for binary search and the power function
//space complexity : O(1)
