from lc_utils import *


class Solution:
    def countCompleteSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        ans = 0
        for u in range(1, min(26, n // k) + 1):
            window = u * k
            offset = 0
            got_k = 0
            cnt = Counter()
            for i, c in enumerate(word):
                if i > 0 and abs(ord(c) - ord(word[i - 1])) > 2:
                    offset = i
                    got_k = 0
                    cnt.clear()
                cnt[c] += 1
                if cnt[c] == k:
                    got_k += 1
                elif cnt[c] == k + 1:
                    got_k -= 1
                left = i - window + 1
                if left < offset:
                    continue
                if got_k == u:
                    ans += 1
                cnt[word[left]] -= 1
                if cnt[word[left]] == k:
                    got_k += 1
                elif cnt[word[left]] == k - 1:
                    got_k -= 1
        return ans
