n = input()

arr = list(map(int, str(n)))

for i in reversed(sorted(arr)):
    print(i, end='')
