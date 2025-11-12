from lc_utils import *


class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        ans = [0] * (len(nums) - k + 1)
        # Alternatives: 1. maintain a multiset of negatives (e.g., sortedcontainers.SortedList) and read lst[x-1]
        # 2. a two-heaps + lazy delete setup to keep the x smallest negatives in a max-heap and the rest in a min-heap
        freq = [0] * 101
        neg_tot = 0
        for i, v in enumerate(nums):
            freq[v + 50] += 1
            neg_tot += v < 0
            if i - k + 1 < 0:
                continue
            if neg_tot >= x:
                y = x
                for j, w in enumerate(freq):
                    y -= w
                    if y <= 0:
                        ans[i - k + 1] = j - 50
                        break
            out = nums[i - k + 1]
            freq[out + 50] -= 1
            neg_tot -= out < 0
        return ans
