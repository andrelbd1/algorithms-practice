#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'equalStacks' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY h1
#  2. INTEGER_ARRAY h2
#  3. INTEGER_ARRAY h3
#

def remove(min_val, s, h):
    while s > min_val:
        s=s-h.pop(0)
    return s, h

def equalStacks(h1, h2, h3):
    s1, s2, s3 = sum(h1), sum(h2), sum(h3)
    while (h1 and h2 and h3):
        if s1==s2==s3:
            return s1
        max_val = max(s1, s2, s3)
        min_val = min(s1, s2, s3)
        if max_val == s1:
            s1, h1 = remove(min_val, s1, h1)
        if max_val == s2:
            s2, h2 = remove(min_val, s2, h2)
        if max_val == s3:
            s3, h3 = remove(min_val, s3, h3)
        
    return 0
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n1 = int(first_multiple_input[0])

    n2 = int(first_multiple_input[1])

    n3 = int(first_multiple_input[2])

    h1 = list(map(int, input().rstrip().split()))

    h2 = list(map(int, input().rstrip().split()))

    h3 = list(map(int, input().rstrip().split()))

    result = equalStacks(h1, h2, h3)

    fptr.write(str(result) + '\n')

    fptr.close()