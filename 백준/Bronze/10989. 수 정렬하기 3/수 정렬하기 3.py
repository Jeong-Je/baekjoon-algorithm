# 10989

import sys

max = 10001
n = int(sys.stdin.readline())
arr = [0] * max

for _ in range(n):
    arr[int(sys.stdin.readline())] += 1

for i in range(max):
    if arr[i] != 0:
        for j in range(arr[i]):
            print(i)