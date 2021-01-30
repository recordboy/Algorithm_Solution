n = int(input())
order = list(input().split())

pos = [1, 1]

# L R D U
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
move = ['L', 'R', 'D', 'U']

for o in order :
    for i in range(len(move)) :
        if o == move[i] :
            nx = pos[1] + dx[i]
            ny = pos[0] + dy[i]
    if not(1 <= nx <= n) or not(1 <= ny <= n):
        continue
    pos[1] = nx
    pos[0] = ny
    print(pos[0], pos[1])
