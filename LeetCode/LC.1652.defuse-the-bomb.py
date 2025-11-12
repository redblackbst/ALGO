from lc_utils import *


class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        tot = 0
        # or could just revert code[] and revert back
        for i in range(abs(k) + n - 1):
            tot += code[i % n]
            if i - abs(k) + 1 < 0:
                continue
            if k > 0:
                ans[i - k] = tot
            elif k < 0:
                ans[(i + 1) % n] = tot
            tot -= code[i - abs(k) + 1]
        return ans
