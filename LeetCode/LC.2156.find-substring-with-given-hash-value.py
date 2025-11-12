from lc_utils import *

c2i = {c: i for i, c in enumerate(ascii_lowercase, start=1)}


class Solution:
    def subStrHash(
        self, s: str, power: int, modulo: int, k: int, hashValue: int
    ) -> str:
        n = len(s)
        pk = pow(power, k - 1, modulo)
        best_pos = 0
        h = 0
        for i in range(n - 1, -1, -1):
            if n - i > k:
                h = (h - c2i[s[i + k]] * pk) % modulo
            h = (h * power + c2i[s[i]]) % modulo
            if n - i >= k and h == hashValue:
                best_pos = i
        return s[best_pos : best_pos + k]
