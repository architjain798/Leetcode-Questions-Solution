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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> ans;
        if(root==NULL){
            return ans;
        }
        queue <TreeNode *> qu;
        ans.push_back(root->val);
        qu.push(root);
        while(qu.size()>0)
        {
            double sum=0,i=0;
            
            int k=qu.size();
            while(k){
                 TreeNode *p=qu.front();
            qu.pop();
            if(p->left!=NULL)
            {
                sum+=p->left->val;
                i++;
                qu.push(p->left);
            }
            if(p->right!=NULL)
            {
                sum+=p->right->val;
                i++;
                qu.push(p->right);
            }
           
                k--;
            }
            if(i!=0)
            ans.push_back(sum/i);
        }
        return ans;
        
    }
};