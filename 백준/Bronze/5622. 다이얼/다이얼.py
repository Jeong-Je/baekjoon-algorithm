# 5622

S = input()
sec = 0
for i in range(len(S)):
    if ord(S[i]) < 68:
        sec += 3
    elif ord(S[i]) < 71:
        sec += 4
    elif ord(S[i]) < 74:
        sec += 5
    elif ord(S[i]) < 77:
        sec += 6
    elif ord(S[i]) < 80:
        sec += 7
    elif ord(S[i]) < 84:
        sec += 8
    elif ord(S[i]) < 87:
        sec += 9
    else:
        sec += 10

print(sec)


