/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (78.12%)
 * Likes:    13986
 * Dislikes: 832
 * Total Accepted:    3M
 * Total Submissions: 3.9M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 *
 * Output: [1,3,2]
 *
 * Explanation:
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
 *
 * Output: [4,2,6,5,7,1,3,9,8]
 *
 * Explanation:
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 *
 * Output: []
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1]
 *
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

// @lc code=start
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
void traverse(struct TreeNode *curr, int *returnSize, int *result)
{
    if (curr->left != NULL)
    {
        traverse(curr->left, returnSize, result);
    }
    result[(*returnSize)++] = curr->val;
    if (curr->right != NULL)
    {
        traverse(curr->right, returnSize, result);
    }
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *result = (int *)malloc(sizeof(int) * 100);
    if (root)
    {
        traverse(root, returnSize, result);
    }
    return result;
}
// @lc code=end
