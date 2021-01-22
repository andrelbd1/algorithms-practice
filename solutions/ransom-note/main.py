import math
import os
import random
import re
import sys
from collections import defaultdict


def checkMagazine(magazine, note):
    d = defaultdict(int)

    for word in magazine:
        d[word] += 1

    for word in note:
        if d[word] == 0:
            print("No")
            return
        d[word] -= 1

    print('Yes')


if __name__ == '__main__':
    input_file = str(sys.argv[1])

    f = open(input_file, "r")
    line1 = f.readline().rstrip()
    line2 = f.readline().rstrip()
    line3 = f.readline().rstrip()

    m = line2.split(" ")
    n = line3.split(" ")

    checkMagazine(m, n)
