hour = int(input())
minute = 60
second = 60
count = 0

for h in range(hour+1) :
    for m in range(minute) :
        for s in range(second) :
            if h%10==3 or m%10==3 or m//10==3 or s%10==3 or s//10==3 :
                count += 1
            else :
                continue

print(count)