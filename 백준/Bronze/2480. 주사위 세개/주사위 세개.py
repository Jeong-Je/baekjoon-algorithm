n1, n2, n3 = map(int, input().split())

result = len(set([n1, n2, n3])) # set 함수는 중복되는 값을 하나로 합침

if result == 1: # 세 숫자가 모두 같을 경우
    print(10000+n1*1000)
elif result == 2: # 세 숫자 중 두개만 같을 경우
    if n1 == n2:
        print(1000+n1*100)
    elif n2 == n3:
        print(1000 + n2 * 100)
    else:
        print(1000 + n3 * 100)
else: # 세 숫자가 모두 다를 경우
    print(max(n1, n2, n3) * 100)

