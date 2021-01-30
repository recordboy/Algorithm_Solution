n, m = map(int, input().split())

graph = []

for i in range(n) :
    graph.append(list(map(int, input())))

def dfs(graph, x, y) :
    if x < 0 or x > n-1 or y < 0 or y > m-1 :
        return False
    if graph[x][y] == 0 :
        graph[x][y] = 1
        dfs(graph, x-1, y)
        dfs(graph, x+1, y)
        dfs(graph, x, y-1)
        dfs(graph, x, y+1)
        return True
    return False

cnt = 0

for i in range(n) :
    for j in range(m) :
        if dfs(graph, i, j) == True :
            cnt += 1

print(cnt)
