/*
Problem Statement: Given a Matrix, print the given matrix in spiral order.

Example 1:
Input: Matrix[][] = { { 1, 2, 3, 4 },
		      { 5, 6, 7, 8 },
		      { 9, 10, 11, 12 },
	              { 13, 14, 15, 16 } }

Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Example 2:
Input: Matrix[][] = { { 1, 2, 3 },
	              { 4, 5, 6 },
		      { 7, 8, 9 } }
			    
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.
  */

/*

Solution : optimal approach (only approach possible)

In this approach, we will be using four loops to print all four sides of the matrix.

1st loop: This will print the elements from left to right.

2nd loop: This will print the elements from top to bottom.

3rd loop: This will print the elements from right to left.

4th loop: This will print the elements from bottom to top.

*/

//pseudo-code : (for the approach only)

// for an n*m matrix

top =0;
bottom = n-1;
left= 0;
right= m-1;

for(i = left to right){
  print mat[top][i];
}
top++;

for(i= top to bottom){
  print mat[i][right];
}
right--;

for(i = right to left){
  print mat[bottom][i];
}
bottom--;

for(i= bottom to top){
  print mat[i][left];
}
left++;


//code

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();

        int left=0, right=m-1;
        int top=0, bottom=n-1;

        vector<int> ans;

        while(top <=bottom && left<=right){
            for(int i = left; i<=right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            for(int i=top; i<=bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            if(top <=bottom){
                for(int i=right; i>=left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            if(left<=right){
                for(int i=bottom; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }

//Time complexity : O(N*M)
//Space complexity : O(N*M) 
















