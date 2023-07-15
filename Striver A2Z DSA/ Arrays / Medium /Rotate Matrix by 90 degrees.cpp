

/*
Solution :

approach 1 : brute force :

take another matrix and store the first row of the matrix in the last column of the new matrix, 
  take the second row of the matrix, and put it in the second last column of the matrix and so on.

the elements will be put as :
for an element arr[i][j] , it will be put at the arr[j][n-1-i] th position.
*/

//pseudo-code :

int ans[n][n];

for(i= 0 to n){
  for(j=0 to n){
    ans[j][n-1-i] = matrix[i][j];
  }
}

// Time complexity : O(N*N)
// Space complexity : O(N*N)

/*
Approach 2 : Optimal approach

In this approach, we will first transpose the entire matrix and in the second step we will reverse each row of the matrix
thus we will get a rotated matrix

*/

//Pseudo-code

//transpose
for(i= 0 to n-2){
  for(j= i+1 to n-1){
    swap(arr[i][j], arr[j][i]);
  }
}
//reverse
for(i= 0 to n-1)
  reverse(matrix[i]);


// code for optimal solution :

void rotate(vector<vector<int>>& matrix) {
        
        int n= matrix.size();

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

//Time complexity : O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
// Space complexity : O(1) 









