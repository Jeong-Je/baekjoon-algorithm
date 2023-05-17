# 1157

s = input()

alphabet = [0] * 26

for i in range(len(s)):
    alphabet[ord(s[i].upper()) - 65] += 1

count = alphabet.count(max(alphabet))
if count != 1:
    print("?")
else:
    print(chr(alphabet.index(max(alphabet)) + 65))




