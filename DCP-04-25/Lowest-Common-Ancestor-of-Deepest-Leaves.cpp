class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }

    TreeNode* findLCA(TreeNode* root, int depth, int maxDepth) {
        if (!root) return nullptr;
        if (depth == maxDepth) return root;

        TreeNode* left = findLCA(root->left, depth + 1, maxDepth);
        TreeNode* right = findLCA(root->right, depth + 1, maxDepth);

        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = getDepth(root);
        return findLCA(root, 1, maxDepth);
    }
};
