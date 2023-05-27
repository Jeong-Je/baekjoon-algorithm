# 2903

N = int(input())

dot = 2
for i in range(N):
    dot = dot + (dot - 1)

print(pow(dot, 2))
