from collections import deque

n, m = map(int, input().split())

maze = []

for _ in range(n) :
    maze.append(list(map(int, input())))

visited = [[False]*m for _ in range(n)]

def bfs(maze, x, y, visited) :
    queue = deque([(x, y)])
    visited[x][y] = True
    maze[x][y] = 1
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]
    while queue :
        print(queue)
        v = queue.popleft()
        x, y = v
        if x == n-1 and y == m-1 :
            print(maze[x][y])
            break
        for i in range(len(dx)) :
            nx = x + dx[i]
            ny = y + dy[i]
            if (nx < 0 or nx > n-1 or ny < 0 or ny > m-1) :
                continue
            elif maze[nx][ny] == 0 or visited[nx][ny] == True :
                continue
            else :
                queue.append((nx, ny))
                visited[nx][ny] = True
                maze[nx][ny] = maze[x][y] + 1
        
bfs(maze, 0, 0, visited)

        
