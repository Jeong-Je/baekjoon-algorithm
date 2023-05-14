# 2908

num1, num2 = input().split()

reversed_num1 = "".join(reversed(num1))
reversed_num2 = "".join(reversed(num2))

if int(reversed_num1) > int(reversed_num2):
    print(reversed_num1)
else:
    print(reversed_num2)