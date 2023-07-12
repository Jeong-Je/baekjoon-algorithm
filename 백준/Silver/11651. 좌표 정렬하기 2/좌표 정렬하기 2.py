import sys
input = sys.stdin.readline

arr = []
n = int(input())

for _ in range(n):
    x, y = map(int, input().split())
    arr.append([y, x])

arr.sort()

for i in range(n):
    print(arr[i][1], arr[i][0])