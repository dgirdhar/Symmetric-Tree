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
    bool isSymmetric(TreeNode* left, TreeNode *right) {
        bool res = false;
        
        if (left == right && left == nullptr) {
            res = true;
        }
        else if (left != nullptr && right != nullptr) {
            if (left->val == right->val) {
                bool leftSymmetry = isSymmetric(left->left, right->right);
                bool rightSymmetry = isSymmetric(left->right, right->left);
                
                if (leftSymmetry & rightSymmetry) {
                    res = true;
                }
            }
        }
        
        return res;
    }
    
    bool isSymmetric(TreeNode* root) {
        bool res = true;
        
        if (root != nullptr) {
            res = isSymmetric(root->left, root->right);
        }
        
        return res;
    }
};
