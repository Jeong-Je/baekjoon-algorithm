year = int(input())

if not(year % 4) and year % 100:
    print('1')
elif not year % 400:
    print('1')
else:
    print('0')
