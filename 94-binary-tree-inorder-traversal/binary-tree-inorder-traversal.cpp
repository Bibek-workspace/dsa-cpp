class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            ans.push_back(node->val);
            inorder(node->right);
        };

        inorder(root);
        return ans;
    }
};