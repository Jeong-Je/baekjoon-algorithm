# 2439
import sys

N = int(sys.stdin.readline())

for i in range(N):
    print(('*' * (i+1)).rjust(N))

