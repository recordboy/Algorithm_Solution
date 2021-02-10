n = int(input())

box = [0] * (n+1)

for i in range(2, n+1) :
    box[i] = box[i-1] + 1
    if i % 2 == 0 :
        box[i] = min(box[i//2]+1, box[i])
    if i % 3 == 0 :
        box[i] = min(box[i//3]+1, box[i])
    if i % 5 == 0 :
        box[i] = min(box[i//5]+1, box[i])

print(box[n])