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
    int longestPath(TreeNode* root, int *diameter) {
      if (root == nullptr) {
        return 0;
      }
      int left = longestPath(root->left, diameter);
      int right = longestPath(root->right, diameter);
      int length = left + right;
      if (length > *diameter) {
        *diameter = length;
      }
      return std::max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
      int diameter = 0;
      longestPath(root, &diameter);
      return diameter;
    }
};
