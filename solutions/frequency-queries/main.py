import math
import os
import random
import re
import sys
from collections import Counter


def freqQuery(queries):
    count = Counter()
    f = Counter()
    lst = []

    for i in queries:
        if i[0] == 1:
            f[count[i[1]]] -= 1
            count[i[1]] += 1
            f[count[i[1]]] += 1
        elif i[0] == 2:
            if count[i[1]] == 0:
                continue
            f[count[i[1]]] -= 1
            count[i[1]] -= 1
            f[count[i[1]]] += 1
        else:
            if f[i[1]] == 0:
                lst.append(0)
            else:
                lst.append(1)
    return lst


if __name__ == '__main__':
    input_file = str(sys.argv[1])

    f = open(input_file, "r")
    n = int(f.readline().rstrip())
    queries = []

    for _ in range(n):
        s = f.readline().strip()
        queries.append(list(map(int, s.rstrip().split())))

    ans = freqQuery(queries)

    for i in ans:
        print(i)
