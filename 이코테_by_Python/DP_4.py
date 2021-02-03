n, m = map(int, input().split())
coin = []
count = [10001] * (m+1)
count[0] = 0

# input all coin
for i in range(n) :
    coin.append(int(input()))

for i in range(n) :
    for j in range(coin[i], m+1) :
        if count[j-coin[i]] != 10001 :
            count[j] = min(count[j], count[j-coin[i]] + 1)

if count[m] == 10001 :
    print(-1)
else :
    print(count[m])