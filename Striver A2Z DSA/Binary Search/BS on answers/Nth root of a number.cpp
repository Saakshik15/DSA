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







