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
 void inorder(struct TreeNode* root, int* val, int* index) {
    if (root) {
        inorder(root->left, val, index);
        val[(*index)++] = root->val;
        inorder(root->right, val, index);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(100*sizeof(int));
    *returnSize = 0;
    inorder(root,array,returnSize);
    return array;
}
