from lc_utils import *


class Solution:
    def fileCombination(self, target: int) -> List[List[int]]:
        k = 2  # item count
        ans = []
        while (k - 1) * k < 2 * target:
            if (target - (k - 1) * k // 2) % k == 0:
                x0 = (target - (k - 1) * k // 2) // k
                ans.append(list(range(x0, x0 + k)))
            k += 1
        return ans[::-1]
