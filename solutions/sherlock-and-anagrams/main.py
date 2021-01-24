import math
import os
import random
import re
import sys
from collections import Counter


def sherlockAndAnagrams(s):
    sub_s = []

    for i in range(1, len(s)):  # Get all possible substrings
        for j in range(0, len(s)-i+1):
            sub_s.append("".join(sorted(s[j:j+i])))

    d_count = Counter(sub_s)

    count = []
    for k, v in d_count.items():
        if v > 1:
            count.append(v)

    total = 0
    for i in count:
        total += sum(range(i))

    return total


if __name__ == '__main__':
    input_file = str(sys.argv[1])

    f = open(input_file, "r")
    q = int(f.readline().rstrip())

    for q_itr in range(q):
        s = f.readline().rstrip()

        print(sherlockAndAnagrams(s))
