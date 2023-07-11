#2587

val = []
for i in range(5):
    val.append(int(input()))

print(int(sum(val)/5))
print(sorted(val)[2])
