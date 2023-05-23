# 2563

paper = [[0 for _ in range(101)] for _ in range(101)] # 100x100 2차원 배열

N = int(input())

for _ in range(N):
    x, y = map(int, input().split())

    for col in range(x, x+10):
        for row in range(y, y+10):
            paper[col][row] = 1

area = 0

for i in paper:
    area += i.count(1)
print(area)
