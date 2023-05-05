A, B = input().split()
C = int(input())

A = int(A)
B = int(B)

B += C

if B + C < 60:
    pass
else:
    A += B//60
    B = B % 60

if A >= 24:
    A -= 24

print(f'{A} {B}')
