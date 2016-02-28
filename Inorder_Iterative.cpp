/*

Given a binary tree, return the inorder traversal of its nodes' values.

Do it iteratively

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> mystack;
        TreeNode* cur = root;
        bool done = 0;
        while(!done){
            if(cur != NULL){
                mystack.push(cur);
                cur = cur->left;
            }
            
            else{
                if(!mystack.empty()){
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
};