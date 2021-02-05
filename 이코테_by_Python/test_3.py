import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

n, d, start = map(int, input().split())

graph = [[] for i in range(n+1)]
distance = [INF] * (n+1)

for _ in range(d) :
    x, y, z = map(int, input().split())
    graph[y].append((x, z))

def dijkstra(start) :
    q = []
    heapq.heappush(q, (0, start))

    distance[start] = 0
    while q :
        dist, now = heapq.heappop(q)
        if distance[now] < dist :
            continue
        for i in graph[now] :
            cost = dist + i[1]
            if cost < distance[i[0]] :
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(start)

cnt = 0
max_distance = 0

for i in distance :
    if i != INF :
        cnt += 1
        max_distance = max(i, max_distance)

print(cnt, max_distance)