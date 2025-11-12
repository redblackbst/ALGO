from lc_utils import *


class Solution:
    def minArrivalsToDiscard(self, arrivals: List[int], w: int, m: int) -> int:
        ans = 0
        cnt = Counter()
        for i, num in enumerate(arrivals):
            if cnt[num] == m:
                arrivals[i] = 0 # mark as discarded
                ans += 1
            else:
                cnt[num] += 1
            if i - w + 1 < 0:
                continue
            print(cnt)
            out = arrivals[i - w + 1]
            if out > 0:
                cnt[out] -= 1
        return ans


if __name__ == "__main__":
    cases = [
        ([1, 2, 1, 3, 1], 4, 2, 0),
        ([7,3,9,9,7,3,5,9,7,2,6,10,9,7,9,1,3,6,2,4,6,2,6,8,4,8,2,7,5,6], 10, 1, 13)
    ]
    for arrivals, w, m, ans in cases:
        print("----")
        sol = Solution().minArrivalsToDiscard(arrivals, w, m)
        print(sol, ans)
        assert sol == ans
