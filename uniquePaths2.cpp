class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid.size() == 0)
            return 0;
            
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int mat[m+1][n+1];
        
        for(int r=0; r<m+1; r++)
            for(int c=0; c<n+1; c++)
                mat[r][c] = 0;
        
        mat[m-1][n]=1;    
        for(int r=m-1; r>=0; r--)
            for(int c=n-1; c>=0; c--)
                mat[r][c] = (obstacleGrid[r][c] == 1) ? 0 : mat[r+1][c] + mat[r][c+1];
        
        return mat[0][0];
        
    }
};
