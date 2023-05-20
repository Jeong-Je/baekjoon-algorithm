# 2566

arr = [list(map(int, input().split())) for _ in range(9)]

max_val = 0
max_col = 0
max_row = 0

for i in range(9):
    for j in range(9):
        if int(arr[i][j]) > int(max_val):
            max_val = arr[i][j]
            max_col = i
            max_row = j

print(max_val)
print(max_col+1, max_row+1)



