/* 
An element is called a leader element if all the elements to its right are smaller than it.

Problem Statement : given an array of N elements, return all the leaders in that array
The last element of the array is always the leader element as there are no elements to the right of it.

*/

/*
Solution :

Approach 1 : Brute Force :

iterate through all the elements of the array and compare the element with all the elements to the right of it.
If there is no element greater than that element then the element is the leader element.
*/
  
//Pseudo-code : 

for(int i=0; i<n; i++){
  leader = true;

  for(int j=i; j<n; j++){
    if(a[j] > a[i]) leader = false;
  }
if(leader == true) ans.add(a[i]);
}

// Time complexity : O(N^2) 
// Space complexity : O(1) ..... constant space
// No extra space to solve the ans but used extra space to store the ans, in that case, O(N)


/*
Approach 2 : 

iterating from the left, check if the current element is greater than the maximum elements from the left.
If the current element is greater than the maximun of all the elements, then it is a leader
so, add it to the ans array and mark the maximun element as that element is the new maximum of the elements
*/

//pseudo-code :

vector<int> ans;
int maximum = INT_MIN;

for(int i=n-1; i>=0; i--){
  if(arr[i] > maximum){
    ans.add(arr[i]);
    maximum = arr[i];
  }
}
return ans;

//time complexity : O(N)
//space complexity : O(1) ..... for solving the answer
//                   O(N) ..... for storing the ans





