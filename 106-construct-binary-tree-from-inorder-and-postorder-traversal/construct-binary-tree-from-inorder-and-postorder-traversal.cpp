class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd) {

        if (inStart > inEnd) {
            return NULL;
        }

        int rootValue = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = mp[rootValue];

        // RIGHT first
        root->right = build(postorder, rootIndex + 1, inEnd);

        // LEFT second
        root->left = build(postorder, inStart, rootIndex - 1);

        return root;
    }
};