/*

Given preorder and inorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(inorder.size() == 0)
            return NULL;
        
        TreeNode* node = new TreeNode(preorder[0]);
        
        vector<int> left;
        int i=0;
        while(inorder[i]!=preorder[0])
        {
            left.push_back(inorder[i]);
            i++;
        }
        
       if(left.size()>0)
            preorder.erase(preorder.begin());
        
       TreeNode* leftChild = buildTree(preorder,left);
       
       node->left = leftChild;
        
        vector<int> right;
        i++;
        while(i != inorder.size())
        {
            right.push_back(inorder[i]);
            i++;
        }
        
        if(right.size()>0)
            preorder.erase(preorder.begin());
        
       TreeNode* rightChild = buildTree(preorder,right);
       
       node->right = rightChild;
        
        return node;
    }
};