# 1546
import sys
N = int(input())
score = list(map(int, input().split()))

high = max(score)

for i in range(N):
    score[i] = (score[i] / high) * 100

print(sum(score)/N)

