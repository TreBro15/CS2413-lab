/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorder(struct TreeNode* root, int* val, int* index) {
    if (root) {
        val[(*index)++] = root->val;
        preorder(root->left, val, index);
        preorder(root->right, val, index);
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    preorder(root, array, returnSize);
    return array;
}
