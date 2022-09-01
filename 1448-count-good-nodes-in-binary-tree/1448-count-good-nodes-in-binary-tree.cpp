/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int helper(TreeNode*root,int maxVal){
        if(root==NULL) return 0;
        int ans=0;
        if(root->val>=maxVal){
            maxVal=max(maxVal,root->val);
            ans++;
        }
        return ans+helper(root->left,maxVal)+helper(root->right,maxVal);
        
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};