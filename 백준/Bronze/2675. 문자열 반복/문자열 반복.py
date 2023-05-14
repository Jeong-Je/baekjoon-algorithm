# 2675

T = int(input())
R = ''

for i in range(T):
    S = input().split()
    for j in range(len(S[1])):
        for k in range(int(S[0])):
            R = R + S[1][j]
    print(R)
    R = ''

