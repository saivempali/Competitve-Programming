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
        int done = 0;
        stack<TreeNode*> mystack;
        TreeNode* cur = root;
        //mystack.push(root);
        
        cout<<"hi1\n";
        
        while(!done)
        {
            if(cur != NULL)
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
        cout<<"hi2\n";
        return result;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> in = inorder(root);
        cout<<"hi";
        return in[k-1];
        
    }
};