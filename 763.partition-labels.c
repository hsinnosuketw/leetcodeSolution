/*
 * @lc app=leetcode id=763 lang=c
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (80.21%)
 * Likes:    10895
 * Dislikes: 426
 * Total Accepted:    692K
 * Total Submissions: 850.4K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * You are given a string s. We want to partition the string into as many parts
 * as possible so that each letter appears in at most one part. For example,
 * the string "ababcc" can be partitioned into ["abab", "cc"], but partitions
 * such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
 *
 * Note that the partition is done so that after concatenating all the parts in
 * order, the resultant string should be s.
 *
 * Return a list of integers representing the size of these parts.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits s into less parts.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "eccbbbbdec"
 * Output: [10]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define max(x, y) (((x) >= (y)) ? (x) : (y))
int *partitionLabels(char *s, int *returnSize)
{
    /*
    Algorithm
    1. Iterate through the string and find the last index of each character.len
    Variables
    1. len : the length of the string
     */
    int len = strlen(s);
    int lastIndex[26] = {0};
    int *ans = (int *)calloc(len, sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < len; i++)
    {
        lastIndex[s[i] - 'a'] = i;
    }

    int left = 0, right = 0;
    for (int i = 0; i < len; i++)
    {
        // Update right index : right will be expanded by the last seen index of the current character
        // And right will be the right-most index of the current partition
        right = max(right, lastIndex[s[i] - 'a']);

        if (i == right)
        {
            ans[(*returnSize)++] = right - left + 1; // Calculate the size of the partition
            left = right + 1;                        // Move the left index to the next character
            right = left;                            // Reset the right index to the left index
        }
    }
    return ans;
}
// @lc code=end
