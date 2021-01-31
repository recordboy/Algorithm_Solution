n = int(input())

num = []
for _ in range(n) :
    num.append(int(input()))

num = sorted(num, reverse = True)

for i in range(n) :
    print(num[i], end = ' ')
