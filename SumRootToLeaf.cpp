/*

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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


    void path(TreeNode* root, string cur, vector<string>& paths)
    {
        if(root->left == NULL && root->right == NULL)
        {
            paths.push_back(cur);
            return;
        }
        
        if(root->left != NULL)
            path(root->left, cur+to_string(root->left->val), paths);
            
        if(root->right != NULL)
            path(root->right, cur+to_string(root->right->val), paths);
    }
    int sumNumbers(TreeNode* root) {
        
        if(root == NULL)
            return 0;
            
        vector<string> paths;
        path(root, to_string(root->val), paths);
        
        int sum = 0;
        size_t sz;
        for(int i=0; i<paths.size(); i++)
        {
            sum += stoi(paths[i],&sz);
        }
        
        return sum;
    }
};