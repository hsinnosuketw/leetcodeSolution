/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (55.63%)
 * Likes:    5639
 * Dislikes: 319
 * Total Accepted:    2.6M
 * Total Submissions: 4.7M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consisting of words and spaces, return the length of the
 * last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 *
 *
 */

// @lc code=start
int lengthOfLastWord(char *s)
{
    int buff = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] != ' ')
        {
            if (i > 0 && s[i - 1] == ' ')
            {
                buff = 1;
            }
            else
            {
                buff++;
            }
        }
        else
        {
            continue;
        }
    }
    return buff;
}
// @lc code=end
