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
  if(n==0) return 1;
  
}
