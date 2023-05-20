# 2566

word = []
for i in range(5):
    a = input()
    word.append(a)


for i in range(15):
    for j in range(5):
        if i < len(word[j]):
            print(word[j][i], end='')

