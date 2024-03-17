class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
    {
        //if cell is out of bounds or already filled or does not have the color asked to fill then return
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val) return;

        image[i][j] = newColor;         //if valid cell, fill it with given color
        dfs(image,i-1,j,val,newColor);  //left
        dfs(image,i+1,j,val,newColor);  //right
        dfs(image,i,j-1,val,newColor);  //down
        dfs(image,i,j+1,val,newColor);  //up
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        //assign the new color to the given cell
        int val = image[sr][sc];

        //perform dfs, becuase we are not asked about the time in which we fill the cells
        dfs(image,sr,sc,val,newColor);
        return image;
    }
};
