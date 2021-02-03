n, m = map(int, input().split())
coin = []
count = [-1] * (m+1)

# input all coin
for i in range(n) :
    coin.append(int(input()))

for i in range(m+1) :
    compare = [0] * n
    for j in coin :
        if i % j == 0 :
           mininum = min(count) 
        else :
            count[i] = -1
