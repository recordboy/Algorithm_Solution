n, m = map(int, input().split())
x, y, direction = map(int, input().split())

# variable for count to visit
cnt = 1
# variable for count to rotate
rotation = 0

visit = [[0]*m for _ in range(m)]
visit[x][y] = 1

gmap = []
for _ in range(n) :
    l = list(map(int, input().split()))
    gmap.append(l)

# 북, 서, 남, 동
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def turn_left() :
    global direction
    direction += 1
    if direction == 4 :
        direction = 0

while True :
    # manual.1 and 2
    # set left direction of now position
    print(x, y, direction)
    turn_left()
    nx = x+dx[direction]
    ny = y+dy[direction]
    if gmap[nx][ny] == 0 and visit[nx][ny] == 0 :
        # check visited block
        visit[nx][ny] = 1
        x = nx
        y = ny
        cnt += 1
        rotation = 0
        continue
    rotation += 1
    # manual.3
    # when rotation 4 time
    if rotation == 4 :
        nx = x-dx[direction]
        ny = y-dy[direction]
        if visit[nx][ny] == 0 :
            x = nx
            y = ny
            rotation = 0
        else :
            break
        
print(cnt)
