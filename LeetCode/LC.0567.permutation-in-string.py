from lc_utils import *


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        k = len(s1)
        d = defaultdict(int)
        for c in s1:
            d[c] += 1
        for i, c in enumerate(s2):
            d[c] -= 1
            if d[c] == 0:
                del d[c]
            left = i - k + 1
            if left < 0:
                continue
            if not d:
                return True
            d[s2[left]] += 1
            if d[s2[left]] == 0:
                del d[s2[left]]
        return False

if __name__ == "__main__":
    cases = [
        ("ab", "eidbaooo", True),
    ]
    for s1, s2, ans in cases:
        sol = Solution().checkInclusion(s1, s2)
        print("----")