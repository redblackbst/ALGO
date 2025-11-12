from lc_utils import *


class Solution:
    def beautifulBouquet(self, flowers: List[int], cnt: int) -> int:
        ans = l = 0
        cnt1 = Counter()
        valid = 0
        for r, x in enumerate(flowers):
            if cnt1[x] == 0:
                valid += 1
            elif cnt1[x] == cnt:
                valid -= 1
            cnt1[x] += 1
            while valid < len(cnt1):
                cnt1[flowers[l]] -= 1
                if cnt1[flowers[l]] == 0:
                    del cnt1[flowers[l]]
                    valid -= 1
                elif cnt1[flowers[l]] == cnt:
                    valid += 1
                l += 1
            ans += r - l + 1
        return ans


if __name__ == "__main__":
    cases = [
        ([1, 2, 3, 2], 1),
    ]
    for flowers, cnt in cases:
        sol = Solution().beautifulBouquet(flowers, cnt)
        print("----")
