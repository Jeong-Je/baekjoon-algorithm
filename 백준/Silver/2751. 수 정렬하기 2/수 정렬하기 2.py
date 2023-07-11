import sys
input=sys.stdin.readline

n = int(input())

val = []

for _ in range(n):
    val.append(int(input()))

for i in sorted(val):
    print(i)