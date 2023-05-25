# 11005

n, b = map(int, input().split())

result = []
while n:
    if n % b >= 10:
        result.append(chr(n%b+55))
    else:
        result.append(n%b)
    n //= b


for i in reversed(result):
    print(i, end='')