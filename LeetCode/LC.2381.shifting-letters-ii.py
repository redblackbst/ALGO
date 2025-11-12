from typing import List
from itertools import accumulate
from string import ascii_lowercase

c2i = {c: i for i, c in enumerate(ascii_lowercase)}


class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        diff = [0] * (n + 1)
        for start, end, direction in shifts:
            step = 2 * direction - 1  # 0 -> -1, 1 -> +1
            diff[start] += step
            if end + 1 <= n:
                diff[end + 1] -= step

        out = []
        for ch, shift in zip(s, accumulate(diff)):
            out.append(ascii_lowercase[(c2i[ch] + shift) % 26])
        return "".join(out)


if __name__ == "__main__":
    cases = [
        # (input_s, input_shifts, expected)
        ("abc", [[0, 1, 0], [1, 2, 1], [0, 2, 1]], "ace"),
        ("dztz", [[0, 0, 0], [1, 1, 1]], "catz"),
    ]
    for i, (s, shifts, expected) in enumerate(cases, 1):
        sol = Solution().shiftingLetters(s, shifts)
        print(f"case {i}: got={sol!r} expected={expected!r}")
        assert sol == expected
