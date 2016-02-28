/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size()==0)
            return NULL;
        
        TreeNode* root = new TreeNode(nums[nums.size()/2]);
        root->val = nums[nums.size()/2];
        vector<int> numsLeft;
        for(int i=0; i<nums.size()/2;i++)
        {
            numsLeft.push_back(nums[i]);
        }
        root->left = sortedArrayToBST(numsLeft);
        
        vector<int> numsRight;
        for(int i = nums.size()/2 + 1; i<nums.size(); i++)
        {
            numsRight.push_back(nums[i]);
        }
        root->right = sortedArrayToBST(numsRight);
        
        return root;
        
    }
};