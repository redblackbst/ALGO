from lc_utils import *


class Solution:
    def containsNearbyAlmostDuplicate(
        self, nums: List[int], indexDiff: int, valueDiff: int
    ) -> bool:
        w = valueDiff + 1
        bmap = {}
        for i, num in enumerate(nums):
            b = num // w
            if b in bmap:
                return True
            if (b - 1 in bmap) and abs(bmap[b - 1] - num) <= valueDiff:
                return True
            if (b + 1 in bmap) and abs(bmap[b + 1] - num) <= valueDiff:
                return True
            bmap[b] = num
            if i >= indexDiff:
                del bmap[nums[i - indexDiff] // w]
        return False


if __name__ == "__main__":
    cases = [
        ([1, 2, 3, 1], 3, 0, True),
    ]
    for nums, indexDiff, valueDiff, ans in cases:
        sol = Solution().containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff)
        print("----")
        assert sol == ans
