from lc_utils import *


class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        ans = avg = 0
        for i, num in enumerate(arr):
            avg += num / k
            left = i - k + 1
            if left < 0:
                continue
            if avg >= threshold:
                ans += 1
            avg -= arr[left] / k
        return ans
