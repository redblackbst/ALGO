from lc_utils import *


class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        pos = defaultdict(list)
        for i, v in enumerate(nums):
            pos[v].append(i)
        best = -1
        for v in pos:
            l = 0
            n = len(pos[v])
            for r in range(n):
                # deletions=(pos[r]−pos[l]+1)−(r−l+1)=pos[r]−pos[l]−(r−l)
                while pos[v][r] - pos[v][l] - (r - l) > k:
                    l += 1
                best = max(best, r - l + 1)
        return best
