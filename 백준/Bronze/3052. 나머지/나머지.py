# 3052

remainder = []
for i in range(10):
    a = int(input())
    remainder.append(a % 42)

print(len(set(remainder)))

