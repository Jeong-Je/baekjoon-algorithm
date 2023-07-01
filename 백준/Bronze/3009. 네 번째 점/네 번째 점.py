x = []
y = []

for _ in range(3):
    x_val, y_val = map(int, input().split())

    x.append(x_val)
    y.append(y_val)

if x.count(x[0]) == 1:
    print(x[0], end=' ')
elif x.count(x[1]) == 1:
    print(x[1], end=' ')
else:
    print(x[2], end=' ')

if y.count(y[0]) == 1:
    print(y[0])
elif y.count(y[1]) == 1:
    print(y[1], end=' ')
else:
    print(y[2], end=' ')
