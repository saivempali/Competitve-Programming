/*

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

*/

class Solution {
public:
    int numTrees(int n) {
       
        if(n<0)
            return 0;
        
        vector<int> arr(n+1,0);
       
        arr[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                arr[i] += arr[j]*arr[i-j-1];
            }
        }
        return arr[n];
        
    }
};