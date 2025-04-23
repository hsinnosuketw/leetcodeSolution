/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (55.29%)
 * Likes:    9830
 * Dislikes: 1035
 * Total Accepted:    1.8M
 * Total Submissions: 3.2M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 *
 *
 */

// @lc code=start
char *addBinary(char *a, char *b)
{
    int len_a = strlen(a), len_b = strlen(b);
    int max_len = (len_a > len_b) ? len_a : len_b;

    // Allocate memory for result (+1 for possible carry, +1 for null terminator)
    char *result = (char *)malloc(max_len + 2);
    if (!result)
        return NULL;

    // Initialize the entire result buffer to zeros
    memset(result, '0', max_len + 1);
    result[max_len + 1] = '\0'; // Null-terminate the string

    int i = 0;
    int carry = 0;

    // Process both strings from right to left
    while (i < len_a || i < len_b || carry)
    {
        int sum = carry;
        if (i < len_a)
            sum += (a[len_a - 1 - i] - '0');
        if (i < len_b)
            sum += (b[len_b - 1 - i] - '0');

        result[max_len - i] = (sum % 2) + '0';
        carry = sum / 2;
        i++;
    }

    // Find the start position (skip leading zeros)
    char *start = result;
    while (*start == '0' && *(start + 1) != '\0') // Skip zeros but keep at least one digit
        start++;

    // Move the result to the beginning of the allocated memory if needed
    if (start > result)
        memmove(result, start, strlen(start) + 1);

    return result;
}
// @lc code=end
