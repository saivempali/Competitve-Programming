/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        vector<vector<int>> result;
        
        if(root == NULL)
            return result;
        
        q.push(root);
        
        TreeNode* temp;
        
        while(!q.empty())
        {
            vector<TreeNode*> arr;
            vector<int> v;
            while(!q.empty())
            {
                arr.push_back(q.front());
                q.pop();
            }
            
            for(int i=0; i<arr.size();i++)
            {
                v.push_back(arr[i]->val);
                if(arr[i]->left != NULL)
                    q.push(arr[i]->left);
                    
                if(arr[i]->right != NULL)
                    q.push(arr[i]->right);
                    
            }
            result.insert(result.begin(),v);
        }
    }
};