#!/usr/bin/env python3
import sys
import math

def compute(n, m, a):
    return math.ceil(n/a) * math.ceil(m/a)

def main():
    for line in sys.stdin:
        result = compute(*tuple(map(int, line.split())))
        print(result)

if __name__ == "__main__":
        main()
