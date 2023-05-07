# 10951
import sys

A, B = 0, 0

while True:
    try:
        A, B = map(int, sys.stdin.readline().split())
        print(A + B)
    except:
        break


