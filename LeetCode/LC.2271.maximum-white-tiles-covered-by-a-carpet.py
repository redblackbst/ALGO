from lc_utils import *


class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles.sort()
        n = len(tiles)
        l = 0
        covered = 0
        ans = 0
        for r in range(n):
            covered += tiles[r][1] - tiles[r][0] + 1
            carpet_left = tiles[r][1] - carpetLen + 1
            while tiles[l][1] < carpet_left:
                covered -= tiles[l][1] - tiles[l][0] + 1
                l += 1
            partial = max(0, carpet_left - tiles[l][0])
            ans = max(ans, covered - partial)
        return ans


if __name__ == "__main__":
    cases = [
        ([[1, 5], [10, 11], [12, 18], [20, 25], [30, 32]], 10, 9),
        ([[10, 11], [1, 1]], 2, 2),
    ]
    for tiles, carpetLen, ans in cases:
        sol = Solution().maximumWhiteTiles(tiles, carpetLen)
        print("----")
        assert sol == ans
