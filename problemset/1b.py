#!/usr/bin/env python3
import re

def ator(s):
    match = re.match('(?P<col>\D+)(?P<row>\d+)', s)
    col_str = match.group('col')
    col = 0
    for i in range(len(col_str)):
        col += (ord(col_str[len(col_str)-1-i])-ord('A')+1)*(26**i)
    result = 'R' + match.group('row') + 'C' + str(col)
    return result

def rtoa(s):
    col_str = []
    match = re.match('R(?P<row>\d+)C(?P<col>\d+)', s)
    col = int(match.group('col'))
    last_zero = False
    while col:
        col = col - 1
        col_str.insert(0, chr((col % 26) + ord('A')))
        if col // 26 == 0:
            break
        col = col // 26
    result = str.join('', col_str) + match.group('row')
    return result

def isr(s):
    match = re.match('R(?P<row>\d+)C(?P<col>\d+)', s)
    return match != None

def main():
    repeat = int(input())
    for i in range(repeat):
        s = input()
        if isr(s):
            print(rtoa(s))
        else:
            print(ator(s))

if __name__ == '__main__':
    main()
