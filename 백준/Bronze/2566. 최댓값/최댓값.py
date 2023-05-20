# 2566

arr = [[0] * 9 for _ in range(9)]

for i in range(9):
    row = input().split()
    for j in range(9):
        arr[i][j] = row[j]

max_val = 0
max_col = 0
max_row = 0

for i in range(9):
    for j in range(9):
        if int(arr[i][j]) > int(max_val):
            max_val = arr[i][j]
            max_col = i
            max_row = j

print(str(max_val) + '\n' + str(int(max_col)+1) + ' ' + str(int(max_row)+1))



