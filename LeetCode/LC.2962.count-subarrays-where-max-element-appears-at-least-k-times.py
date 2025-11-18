from lc_utils import *


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = l = 0
        target = max(nums)
        cnt = 0
        for r, x in enumerate(nums):
            cnt += x == target
            while cnt == k:
                cnt -= nums[l] == target
                l += 1
            ans += l
        return ans


# Extra problem
class Solution1:
    # If the problem is altered to: the max element of the SUBARRAY appears at least k times in the SUBARRAY
    def countSubarrays2(self, nums: List[int], k: int) -> int:
        ans = 0
        nums.append(max(nums) + 1)  # to help clear the stack
        st = [-1]
        for i, x in enumerate(nums):
            # Maintain a non-decreasing stack that allow duplicates, hence <
            while len(st) > 1 and nums[st[-1]] < x:
                if len(st) > k and nums[st[-k]] == nums[st[-1]]:
                    ans += (st[-k] - st[-k - 1]) * (i - st[-1])
                st.pop()
            st.append(i)
        return ans


def solve1(a, k):  # n方暴力
    n = len(a)
    ans = 0
    for l in range(n):
        mx = a[l]
        cnt = 0
        for r in range(l, n):
            if a[r] == mx:
                cnt += 1
            elif a[r] > mx:
                mx = a[r]
                cnt = 1
            if cnt >= k:
                ans += 1
    return ans


def solve2(a, k):  # 单调栈+乘法原理
    n = len(a)
    pos = defaultdict(list)
    left = [-1] * n
    st = []
    for i, v in enumerate(a):
        pos[v].append(i)
        while st and a[st[-1]] <= v:
            st.pop()
        if st:
            left[i] = st[-1]
        st.append(i)
    right = [n] * n
    st = []
    for i, v in enumerate(a):
        while st and a[st[-1]] < v:
            right[st.pop()] = i
        st.append(i)
    ans = 0
    for v, p in pos.items():
        if len(p) < k: continue
        p = [left[p[0]]] + p
        l = 1
        for r in range(k, len(p)):
            if left[p[l]] == left[p[r]] and right[p[l]] == right[p[r]]:
                ans += (p[l] - max(p[l - 1], left[p[l]])) * (right[p[r]] - p[r])
            l += 1
    return ans


MX = 1000
for _ in range(10000):  # 对拍
    n = randint(1, MX)
    k = randint(1, n)
    a = [randint(1, MX) for _ in range(n)]

    if solve1(a, k) != solve2(a, k):
        print(n, k)
        print(a)
        print(solve1(a, k))
        print(solve2(a, k))