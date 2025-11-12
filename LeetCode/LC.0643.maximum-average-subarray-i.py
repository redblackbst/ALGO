from lc_utils import *


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        ans = -1e9
        avg = 0
        for i, num in enumerate(nums):
            avg += num / k
            left = i - k + 1
            if left < 0:
                continue
            ans = max(ans, avg)
            avg -= nums[left] / k
        return ans


if __name__ == "__main__":
    cases = [
        ([-1], 1, -1.0),
    ]
    for i, (nums, k, ans) in enumerate(cases, 1):
        sol = Solution().findMaxAverage(nums, k)
        print(f"case {i}: got={sol!r} expected={ans!r}")
        assert sol == ans
