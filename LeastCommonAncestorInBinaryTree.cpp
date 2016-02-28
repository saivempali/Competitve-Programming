/*

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

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

    bool findpath(TreeNode* root, TreeNode* n,vector<TreeNode*> path)
    {
        path.push_back(root);
     
        if(root->val == n->val)
        {
            return true;
        }
        
        if(findpath(root->left,n,path) || findpath(root->right,n,path))
            return true;
            
        path.pop_back();
        return false;
            
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p == NULL || q == NULL || root == NULL)
            return root;
            
        vector<TreeNode*> p1,p2;
        
        if(findpath(root,p,p1) && findpath(root,q,p2))
        {
            for(int i=0; i < p1.size()&&p2.size(); i++)
            {
                if(p1[i] != p2[i])
                {
                    return p1[i-1];
                }
            }
        }
        
        return root;
        
    }
};