#
# @lc app=leetcode id=3392 lang=python3
#
# [3392] Count Subarrays of Length Three With a Condition
#
# https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/
#
# algorithms
# Easy (52.98%)
# Likes:    95
# Dislikes: 15
# Total Accepted:    48.7K
# Total Submissions: 86K
# Testcase Example:  '[1,2,1,4,1]'
#
# Given an integer array nums, return the number of subarrays of length 3 such
# that the sum of the first and third numbers equals exactly half of the second
# number.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,2,1,4,1]
# 
# Output: 1
# 
# Explanation:
# 
# Only the subarray [1,4,1] contains exactly 3 elements where the sum of the
# first and third numbers equals half the middle number.
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,1,1]
# 
# Output: 0
# 
# Explanation:
# 
# [1,1,1] is the only subarray of length 3. However, its first and third
# numbers do not add to half the middle number.
# 
# 
# 
# Constraints:
# 
# 
# 3 <= nums.length <= 100
# -100 <= nums[i] <= 100
# 
# 
#

# @lc code=start
class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        """
        1. for loop iterate throught the array, end before the last 2 elements
        2. sum the i and i + 2 elements 
        3. check the sum is half the middle element
        (divide by 2 with // avoiding the floating point) and middle element is even
        4. if so, increment the count
        Time complexity: O(n)
        Space complexity: O(1)
        """
        count = 0
        for i in range(len(nums) - 2):
            if (nums[i] + nums[i + 2]) == nums[i + 1]//2 and (nums[i+1]) % 2 == 0:
                count += 1
        return count
# @lc code=end

