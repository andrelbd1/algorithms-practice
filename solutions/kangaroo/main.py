import math
import os
import re
import sys

# v1*j+x1 == v2*j+x2
# v1*j-v2*j==x2-x1
# j(v1-v2)==x2-x1
# j==x2-x1/v1-v2

def kangaroo(x1, v1, x2, v2):
    if x1!=x2 and v1==v2:
        return "NO"
        
    if (x2-x1)%(v1-v2)==0:
        if ((x2-x1)/(v1-v2)) > 0:
            return "YES"
    return "NO"

if __name__ == '__main__':
    input_file = str(sys.argv[1])

    f = open(input_file, "r")
    line = f.readline().rstrip()
    line = line.split(" ")
    
    print(kangaroo(int(line[0]), int(line[1]), int(line[2]), int(line[3])))