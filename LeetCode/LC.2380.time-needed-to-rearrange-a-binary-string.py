# key: pre0

class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:
        f = pre0 = 0
        for c in s:
            if c == '0': pre0 += 1
            elif pre0: f = max(f + 1, pre0)
        return f