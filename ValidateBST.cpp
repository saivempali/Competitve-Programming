/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

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

    vector<int> inorder(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> mystack;
        int done = 0;
        TreeNode* cur = root;
        while(!done)
        {
            if(cur!=NULL)
            {
                mystack.push(cur);
                cur = cur->left;
            }
            
            else
            {
                if(!mystack.empty())
                {
                    cur = mystack.top();
                    mystack.pop();
                    result.push_back(cur->val);
                    cur = cur->right;
                }
                
                else
                    done = 1;
                
            }
            
        }
        return result;
    }
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL)
            return true;
     
        vector<int> arr = inorder(root);
        
        cout<<arr.size();
        
        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr[i] >= arr[i+1])
            {
                return false;
            }
        }
        
        return true;
    }
};