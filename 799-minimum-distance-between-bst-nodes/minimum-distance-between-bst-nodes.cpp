class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            inorder(node->left);

            if (prev != -1)
                ans = min(ans, node->val - prev);

            prev = node->val;

            inorder(node->right);
        };

        inorder(root);
        return ans;
    }
};