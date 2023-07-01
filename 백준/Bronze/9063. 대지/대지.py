x = []
y = []

n = int(input())

for _ in range(n):
    x_val, y_val = map(int, input().split())
    x.append(x_val)
    y.append(y_val)

print((max(x)-min(x))*(max(y)-min(y)))