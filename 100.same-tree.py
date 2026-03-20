#
# @lc app=leetcode id=100 lang=python
#
# [100] Same Tree
#
# https://leetcode.com/problems/same-tree/description/
#
# algorithms
# Easy (64.57%)
# Likes:    12615
# Dislikes: 288
# Total Accepted:    3.1M
# Total Submissions: 4.7M
# Testcase Example:  '[1,2,3]\n[1,2,3]'
#
# Given the roots of two binary trees p and q, write a function to check if
# they are the same or not.
# 
# Two binary trees are considered the same if they are structurally identical,
# and the nodes have the same value.
# 
# 
# Example 1:
# 
# 
# Input: p = [1,2,3], q = [1,2,3]
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: p = [1,2], q = [1,null,2]
# Output: false
# 
# 
# Example 3:
# 
# 
# Input: p = [1,2,1], q = [1,1,2]
# Output: false
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in both trees is in the range [0, 100].
# -10^4 <= Node.val <= 10^4
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def isSameTree(self, p, q):
        """
        Iterative approach using BFS (Queue). 
        Avoids RecursionLimit errors on deep trees.
        """
        queue = deque([(p, q)])

        while queue:
            node_p, node_q = queue.popleft()

            # If both are None, continue to next siblings
            if not node_p and not node_q:
                continue
            
            # If structure mismatch (one None) or value mismatch
            if not node_p or not node_q or node_p.val != node_q.val:
                return False
            
            # Add children to queue for future processing
            queue.append((node_p.left, node_q.left))
            queue.append((node_p.right, node_q.right))
            
        return True
# @lc code=end

