/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    *returnSize = digitsSize;
    int carry = 0;
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (i == digitsSize - 1)
            digits[i]++;
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
        if (carry == 0)
            return digits;
    }
    *returnSize = digitsSize + 1;
    int *ans = (int *)malloc(sizeof(int) * (digitsSize + 1));
    if (carry = 1)
    {

        for (int i = digitsSize - 1; i >= 0; i--)
        {
            ans[i + 1] = digits[i];
        }
        ans[0] = 1;
    }
    return ans;
}
// @lc code=end
