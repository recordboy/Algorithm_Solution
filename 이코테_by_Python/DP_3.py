n = int(input())

box = [0] * (n+1)

box[1] = 1
box[2] = 3

for i in range(3, n+1) :
    box[i] = (box[i-1] + box[i-2] * 2) % 796796

print(box[n])