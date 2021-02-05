n, m = map(int, input().split())

price = []

for _ in range(m) :
    six, one = map(int, input().split())
    price.append((six/6, six, True))
    price.append((one, one, False))

price = sorted(price, key = lambda x : x[0])

total = 0
set_op = False


if price[0][2] == False :
    total += n * price[0][1]
elif price[0][2] == True :
    total += (n//6) * price[0][1]
    n = (n % 6)
    set_op = True


not_set_index = 0
if set_op == True :
    for i in range(1, m*2) :
        if price[i][2] == False :
            not_set_index = i
            #print(i, not_set_index)
            break
    total += n * price[not_set_index][1]

print(total)
