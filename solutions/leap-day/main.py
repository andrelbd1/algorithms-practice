import math
import os
import re
import sys

def is_leap(year):
    if year%4 == 0:
        if year%100==0:
            if year%400==0:
                return True
        else:
            return True

    return False

if __name__ == '__main__':
    input_file = str(sys.argv[1])

    f = open(input_file, "r")
    year = int(f.readline().rstrip())

    print(is_leap(year))