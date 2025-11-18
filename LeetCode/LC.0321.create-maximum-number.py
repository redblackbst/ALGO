from lc_utils import *


class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def pickMax(nums: List[int], k: int) -> List[int]:
            st = []
            drop = len(nums) - k
            for x in nums:
                while drop and st and st[-1] < x:
                    st.pop()
                    drop -= 1
                st.append(x)
            return st[:k]

        def merge(A: List[int], B: List[int]) -> List[int]:
            ans = []
            while A or B:
                bigger = A if A > B else B
                ans.append(bigger[0])
                bigger.pop(0)
            return ans

        return max(
            merge(pickMax(nums1, i), pickMax(nums2, k - i))
            for i in range(k + 1)
            if i <= len(nums1) and k - i <= len(nums2)
        )
