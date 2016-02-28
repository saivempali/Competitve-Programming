/*

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int maxp(TreeNode* root, int& maxsum)
    {
        if(root == NULL)
            return 0;
            
        int l = maxp(root->left,maxsum);
        int r = maxp(root->right,maxsum);
        
        int max1 = max(max(l,r)+root->val,root->val);
        int max2 = max(max1, l+r+root->val);
        
        maxsum = max(maxsum,max2);
        
        return max1;
    }
    
    int maxPathSum(TreeNode* root) {
        
        if(root == NULL)
            return 0;
            
        int maxsum = INT_MIN;
        maxp(root,maxsum);
        return maxsum;
    }
    

};