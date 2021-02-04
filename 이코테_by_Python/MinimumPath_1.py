v, e = map(int, input().split())
INF = int(1e9)
graph = [[INF]*(v+1) for _ in range (v+1)]

for i in range(1, v+1) :
    for j in range(1, v+1) :
        if i==j :
            graph[i][j] = 0 

for i in range(e) :
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

company, date = map(int, input().split())

for k in range(1, v+1) :
    for i in range(1, v+1) :
        for j in range(1, v+1) :
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

total_dist = graph[1][date] + graph[date][company]

if total_dist >= INF :
    print(-1)
else :
    print(total_dist)