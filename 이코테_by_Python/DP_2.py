n = int(input())
container = list(map(int, input().split()))

total = [0] * n

total[0] = container[0]
total[1] = max(total[0], container[1])

for i in range(2, n) :
    total[i] = max(total[i-1], total[i-2] + container[i])

print(total[n-1])