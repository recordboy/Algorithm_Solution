v = int(input())
e = int(input())

graph = [[] for i in range(v+1)]

for _ in range(e) :
    f, t = map(int, input().split())
    graph[f].append(t)
    graph[t].append(f)

print(graph)

visited = [False] * (v+1)

total = 0

sub = graph[1]
visited[1] = True

for i in graph[1] :
    if visited[i] :
        continue
    else :
        visited[i] = True
        total += 1 

for j in sub :
    for k in graph[j] :
        if visited[k] :
            continue
        else :
            visited[k] = True
            total += 1 

print(total)