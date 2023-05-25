# 11005

arr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ans = ''
n, b = map(int, input().split())

while n:
    ans += arr[n%b]
    n //= b

print(ans[::-1])