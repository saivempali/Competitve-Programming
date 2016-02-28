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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        
        if(root == NULL)
            return result;
            
        int done = 0;
        stack<TreeNode*> mystack;
        TreeNode* cur = root;
        
        while(!done)
        {
            if(cur!=NULL)
            {
                result.push_back(cur->val);
                mystack.push(cur);
                cur = cur->left;
            }
            
            else
            {
                if(!mystack.empty())
                {
                    cur = mystack.top();
                    mystack.pop();
                    cur = cur->right;
                }
                
                else
                    done = 1;
            }
        }
        return result;
    }
};
