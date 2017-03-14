class Solution {
public:
    int climbStairs(int n) {
        
        // base case f(1) = 1, f(2) = 2
        
        // 1st step taken
        int step1=1, step2=1;
        
        // calculating from 2nd step to nth step
        for(int i=2; i<=n; i++)
        {
            int temp = step2;
            step2 += step1;
            step1 = temp;
        }
        return step2;
    }
};
