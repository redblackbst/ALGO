from lc_utils import *


class Solution:
    def arrangeBookshelf(self, order: List[int], limit: int) -> List[int]:
        st = []
        cnt = Counter(order)
        cnt1 = Counter()
        for x in cnt:
            cnt[x] = max(0, cnt[x] - limit)
        for x in order:
            if cnt1[x] < limit:
                while st and st[-1] > x and cnt[st[-1]] > 0:
                    y = st.pop()
                    cnt[y] -= 1
                    cnt1[y] -= 1
                st.append(x)
                cnt1[x] += 1
            else:
                cnt[x] -= 1
        return st


if __name__ == "__main__":
    cases = [
        ([10, 4, 12, 1, 6, 10, 1, 10, 2, 10, 10, 7], 1, [4, 12, 1, 6, 2, 10, 7]),
    ]
    for order, limit, ans in cases:
        sol = Solution().arrangeBookshelf(order, limit)
        print("----")
