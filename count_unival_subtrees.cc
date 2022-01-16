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
    bool isUnivalSubtree(TreeNode* root, int val) {
      if (!root) {
        return false;
      }
      if (root->val != val) {
        return false;
      }
      if (root->left == nullptr && root->right == nullptr) {
        return true;
      }
      bool l = true;
      if (root->left) {
        l = isUnivalSubtree(root->left, val);
      }
      bool r = true;
      if (root->right) {
        r = isUnivalSubtree(root->right, val);
      }
      return l && r;
    }
  
    int countUnivalSubtrees(TreeNode* root) {
      int count = 0;
      stack<TreeNode*> s;
      if (root) {
        s.push(root);
      }
      while (!s.empty()) {
        TreeNode* curr = s.top();
        s.pop();
        if (isUnivalSubtree(curr, curr->val)) {
          count++;
        }
        if (curr->left) {
          s.push(curr->left);
        }
        if (curr->right) {
          s.push(curr->right);
        }
      }
      return count;
    }
};
