from lc_utils import *


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        ans = []
        st = []
        while head:
            while st and st[-1][1] < head.val:
                ans[st.pop()[0]] = head.val
            st.append((len(ans), head.val))
            ans.append(0)  # placeholder
            head = head.next
        return ans
