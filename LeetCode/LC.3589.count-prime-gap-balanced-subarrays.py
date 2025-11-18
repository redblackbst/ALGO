from lc_utils import *

MX = 50_001
is_prime = [False] * 2 + [True] * (MX - 2)
for i in range(2, isqrt(MX) + 1):
    if is_prime[i]:
        for j in range(i * i, MX, i):
            is_prime[j] = False


class Solution:
    def primeSubarray(self, nums: List[int], k: int) -> int:
        max_q = deque()
        min_q = deque()
        ans = left = 0
        last2 = last = -1
        for i, x in enumerate(nums):
            if is_prime[x]:
                last2 = last
                last = i
                while min_q and nums[min_q[-1]] >= x:
                    min_q.pop()
                min_q.append(i)
                while max_q and nums[max_q[-1]] <= x:
                    max_q.pop()
                max_q.append(i)
                while nums[max_q[0]] - nums[min_q[0]] > k:
                    left += 1
                    if min_q[0] < left:
                        min_q.popleft()
                    if max_q[0] < left:
                        max_q.popleft()
            ans += last2 - left + 1  # [left, last2]
        return ans
