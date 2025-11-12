from lc_utils import *


class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        ss = Counter()
        cnt = Counter()
        for i, c in enumerate(s):
            ss[c] += 1
            if i - minSize + 1 < 0:
                continue
            if len(ss) <= maxLetters:
                cnt[s[i - minSize + 1 : i + 1]] += 1
            out = s[i - minSize + 1]
            ss[out] -= 1
            if ss[out] == 0:
                del ss[out]
        return max(cnt.values()) if cnt else 0


if __name__ == "__main__":
    cases = [
        ("aababcaab", 2, 3, 4),
        (
            "eddcdfcfbbbdedbcddebbfbbdddacfecddacabdbddabfffdecebcabfbdeadecffbcdccecdebbaaaeebefbabeaefbebecdfcd",
            1,
            5,
            24,
        ),
    ]
    for s, maxLetters, minSize, maxSize in cases:
        sol = Solution().maxFreq(s, maxLetters, minSize, maxSize)
        print("----")
        # print(sol)
