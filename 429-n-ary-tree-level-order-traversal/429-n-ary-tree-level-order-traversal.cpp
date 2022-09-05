/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:
        vector<vector < int>> levelOrder(Node *root)
        {
            vector<vector < int>> ans;

            if (root == NULL) return ans;

            vector<int> r;
            queue<Node*> qu;
            qu.push(root);
            r.push_back(root->val);
            ans.push_back(r);
            while (qu.size())
            {
                int k = qu.size();
                vector<int> vp;
                while (k)
                {
                    Node *p = qu.front();
                    qu.pop();

                    
                    for (int i = 0; i < p->children.size(); i++)
                    {
                        qu.push(p->children[i]);
                        vp.push_back(p->children[i]->val);
                    }
                   
                    k--;
                }
                
                 if (vp.size() > 0)
                    {
                        ans.push_back(vp);
                    }

                
            }

            return ans;
        }
};