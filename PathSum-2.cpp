/*

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
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


    void hasPath(TreeNode* root, int sum, vector<vector<int>>& result, vector<int>& tempresult)
    {
        if(root == NULL)
            return ;
            
        vector<int> temp = tempresult;
        if(sum - root->val == 0)
        {
            if(root->left == NULL && root->right == NULL)
            {
                temp.push_back(root->val);
                result.push_back(temp);
                return ;
            }
        }
        temp.push_back(root->val);
        hasPath(root->left, sum - root->val, result, temp);
        hasPath(root->right, sum - root->val, result, temp);
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> result;
        vector<int> tempresult;
        if(root == NULL)
            return result;
            
        hasPath(root, sum, result, tempresult);
        return result;
    }
};