"""
Common imports + tiny helpers for local LeetCode debugging.

Usage (prefer explicit imports):
    from lc_utils import List, Optional, accumulate, ascii_lowercase, Counter, deque

Or quick-and-dirty:
    from lc_utils import *
"""

from __future__ import annotations

# --- typing ---
from typing import (
    Any,
    Callable,
    Deque,
    DefaultDict,
    Dict,
    Generator,
    Iterable,
    Iterator,
    List,
    Literal,
    Optional,
    Set,
    Tuple,
    TypeVar,
    Counter as TypingCounter,
)

# --- stdlib data structures ---
from collections import Counter, defaultdict, deque

# --- algorithms & utilities ---
from heapq import heappop, heappush, heapify, heapreplace
from bisect import bisect_left, bisect_right, insort
from itertools import accumulate, combinations, permutations, product, groupby
try:  # Python 3.10+
    from itertools import pairwise  # type: ignore[attr-defined]
except Exception:  # fallback for 3.9
    def pairwise(iterable):
        it = iter(iterable)
        prev = next(it, None)
        for cur in it:
            yield prev, cur
            prev = cur

from functools import lru_cache, cache, reduce

# --- math & strings ---
from math import inf, ceil, floor, gcd, sqrt, factorial, log2, atan2, pi, lcm, gcd
from string import ascii_lowercase, ascii_uppercase

# --- dataclasses (occasionally handy) ---
from dataclasses import dataclass

# --- small conveniences ---
INF = float("inf")
NEG_INF = float("-inf")
DIR4: Tuple[Tuple[int, int], ...] = ((1, 0), (-1, 0), (0, 1), (0, -1))
DIR8: Tuple[Tuple[int, int], ...] = DIR4 + ((1, 1), (1, -1), (-1, 1), (-1, -1))

# --- common LeetCode node stubs (for local type checking / debugging) ---
class ListNode:
    __slots__ = ("val", "next")

    def __init__(self, val: int = 0, next: "Optional[ListNode]" = None):
        self.val = val
        self.next = next


class TreeNode:
    __slots__ = ("val", "left", "right")

    def __init__(
        self,
        val: int = 0,
        left: "Optional[TreeNode]" = None,
        right: "Optional[TreeNode]" = None,
    ):
        self.val = val
        self.left = left
        self.right = right


__all__ = [
    # typing
    "Any","Callable","Deque","DefaultDict","Dict","Generator","Iterable","Iterator","List",
    "Literal","Optional","Set","Tuple","TypeVar","TypingCounter",
    # collections
    "Counter","defaultdict","deque",
    # heapq/bisect/itertools/functools
    "heappop","heappush","heapify","heapreplace","bisect_left","bisect_right","insort",
    "accumulate","combinations","permutations","product","groupby","pairwise",
    "lru_cache","cache","reduce",
    # math/string and constants
    "inf","ceil","floor","gcd","sqrt","factorial","log2","atan2","pi","lcm","gcd",
    "ascii_lowercase","ascii_uppercase","INF","NEG_INF","DIR4","DIR8",
    # dataclasses
    "dataclass",
    # nodes
    "ListNode","TreeNode",
]
