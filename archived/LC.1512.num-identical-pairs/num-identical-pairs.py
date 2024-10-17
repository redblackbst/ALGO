from typing import List

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        # list has a `count` method
        return sum(nums[:j].count(nums[j]) for j in range(len(nums)))

print(Solution().numIdenticalPairs([1,2,3,1,1,3]))
print(Solution().numIdenticalPairs([1,1,1,1]))
print(Solution().numIdenticalPairs([[1,2,3]]))