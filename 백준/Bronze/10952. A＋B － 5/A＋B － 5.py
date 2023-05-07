# 10952
import sys

A, B = 0, 0

while True:
    A, B = map(int, sys.stdin.readline().split())
    if A == 0 and B == 0:
        break
    print(A+B)


