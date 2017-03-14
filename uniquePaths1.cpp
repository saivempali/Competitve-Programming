
/*
// backtracking
int backtrack(int r, int c, int m, int n)
{
    if(r == m-1 || c == n-1)
        return 1;
    if(r >= m || c >= n)
        return 0;
    
    return backtrack(r+1, c, m, n) + backtrack(r, c+1, m, n);
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        return backtrack(0,0,m,n);
        
    }
};
*/

// DP solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int mat[m+1][n+1];
        
        for(int r=0; r<m+1; r++)
            for(int c=0; c<n+1; c++)
                mat[r][c] = 0;
        
        mat[m-1][n] = 1;
        
        for(int r=m-1; r>=0; r--)
        {
            for(int c=n-1; c>=0; c--)
            {
                mat[r][c] = mat[r+1][c] + mat[r][c+1];
            }
        }
        return mat[0][0];
    }
};
