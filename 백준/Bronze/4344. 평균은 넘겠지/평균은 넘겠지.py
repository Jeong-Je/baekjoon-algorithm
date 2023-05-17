# 4344

c = int(input())

for i in range(c):
    N = list(map(int, input().split()))
    total = sum(N) - N[0]
    avg = total / N[0]
    cnt = 0
    for j in range(N[0]):
        if N[j+1] > avg:
            cnt += 1
    print(f'{round(cnt / N[0] * 100, 3):.3f}%')
