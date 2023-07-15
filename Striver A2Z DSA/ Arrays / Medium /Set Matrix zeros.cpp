/*

Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column 
and row to 0 and then return the matrix.

*/

/*
solution :

Approach 1 : brute force 

First, we will use two loops(nested loops) to traverse all the cells of the matrix.
If any cell (i,j) contains the value 0, we will mark all cells in row i and column j with -1 except those which contain 0.
  because initially if we mark the cells as 0 instead of -1, we will end up creating an ambiguity about the elements which were not 
  0 at the initial and also mark the elements associated with them as 0
  We will do it for every cell containing 0.
Finally, we will mark all the cells containing -1 with 0.

Time Complexity: O((N*M)*(N + M)) + O(N*M),
  where N = no. of rows in the matrix and M = no. of columns in the matrix.

Space Complexity: O(1) as we are not using any extra space.
*/
/*
Approach 2 : better solution

First, we will declare two arrays: a row array of size N and a col array of size M and both are initialized with 0.
Then, we will traverse the array and check if any cell (i,j) contains the value 0, 
  we will mark ith index of row array row[i] and jth index of col array col[j] as 1. 
  It is done so that all the elements in the ith row and jth column will be 0 in the final matrix.
we will again traverse the entire matrix and we will put 0 into all the cells (i, j) for 
  which either row[i] or col[j] is marked as 1.
*/


//pseudo-code : 

for(i=0 to n){
  for(j=0 to m){
    if(arr[i][j] == 0) {
      row[i] == 1;
      col[j] == 1;
    }
  }
}
for( i = 0 to n){
  for(j = 0 to m){
    if(row[i] || col[j])
      a[i][j] = 0;
 }
}

// Time complexity : O(2*N*M)
// Space complexity : O(N)+O(M)

code for better solution :

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}


/*
Approach 3 : better solution :

this approach is similar to the approach of the better solution, but to optimize the space complexity we will not be using the extra space we used
instead of creating the extra arrays, we will keep the track of zeors in the 0th row and 0th column of the matrix itself
the corner element which occurs at the matrix[0][0] we will create another variable for that.
while converting zeros we have to make sure that we do not start from the oth row and colummn but from the other rows and columns
after that, while converting the row and column finallly we have to first convert the row and then column 
*/

// code:

void setZeroes(vector<vector<int>>& matrix) {
        int col0 =1;
        int n=matrix.size();
        int m= matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;

                    if(j!=0) matrix[0][j]=0;
                    else col0 = 0;
                }
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }

// Time complexity : O(2*(N*M))
// Space complexity : O(1)













