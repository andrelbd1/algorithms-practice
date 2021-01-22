import math
import os
import random
import re
import sys
from collections import defaultdict


def twoStrings(s1, s2):
    for i in s1:
        if i in s2:
            return "YES"
    return "NO"


if __name__ == '__main__':
    input_file = str(sys.argv[1])

    f = open(input_file, "r")
    q = int(f.readline().rstrip())

    for q_itr in range(q):
        s1 = f.readline().rstrip()
        s2 = f.readline().rstrip()

        print(twoStrings(s1, s2))
