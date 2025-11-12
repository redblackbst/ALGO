from lc_utils import *


class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        allCodes = set()
        n = len(s)
        for i in range(n - k + 1):
            allCodes.add(s[i : i + k])
        return len(allCodes) == 2**k


if __name__ == "__main__":
    cases = [
        ("00110110", 2, True),
    ]
    for s, k, ans in cases:
        sol = Solution().hasAllCodes(s, k)
        print("----")
