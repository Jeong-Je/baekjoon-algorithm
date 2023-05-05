H, M = input().split()

H = int(H)
M = int(M)

if M >= 45: # M이 45이 이상일 경우 -> H는 상관 X
    print(f'{H} {M-45}')
elif M < 45 and H > 0 : # H는 1시 이상이면서 M은 45 미만일 경우
    print(f'{H-1} {60+(M-45)}')
else: # H가 1 이면서 M이 45 미만일 경우
    print(f'23 {60+(M-45)}')
