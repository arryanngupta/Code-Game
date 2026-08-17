class Solution {
public:

    bool isLeaf(Node* node) {
        return node && !node->left && !node->right;
    }

    // Left boundary
    void leftBoundary(Node* node, vector<int>& ans) {
        if (!node || isLeaf(node))
            return;

        ans.push_back(node->data);

        if (node->left)
            leftBoundary(node->left, ans);
        else
            leftBoundary(node->right, ans);
    }

    // All leaf nodes
    void leaf(Node* node, vector<int>& ans) {
        if (!node)
            return;

        if (isLeaf(node)) {
            ans.push_back(node->data);
            return;
        }

        leaf(node->left, ans);
        leaf(node->right, ans);
    }

    // Right boundary in reverse
    void rightBoundary(Node* node, vector<int>& ans) {
        if (!node || isLeaf(node))
            return;

        if (node->right)
            rightBoundary(node->right, ans);
        else
            rightBoundary(node->left, ans);

        ans.push_back(node->data);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;

        if (!root)
            return ans;

        // Special case: root itself is a leaf
        if (!isLeaf(root))
            ans.push_back(root->data);

        leftBoundary(root->left, ans);

        leaf(root, ans);

        rightBoundary(root->right, ans);

        return ans;
    }
};