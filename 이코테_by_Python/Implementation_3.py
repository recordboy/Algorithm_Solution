pos = input()
cnt = 0

row = int(pos[1])
col = ord(pos[0])-ord('a')+1

# (row, col)
fix = [(-1, -2), (-2, -1), (1, -2), (2, -1), (-1, 2), (-2, 1), (1, 2), (2, 1)]

for npos in fix :
    nrow = row+npos[0]
    ncol = col+npos[1]
    if 1<=nrow<=8 and 1<=ncol<=8 :
        cnt += 1

print(cnt)