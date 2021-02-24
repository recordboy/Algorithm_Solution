N, M = map(int, input().split())
A = []
for i in range(N) :
  A.append(list(map(int, input().split())))
M, K = map(int, input().split())
B = []
for i in range(M) :
  B.append(list(map(int, input().split())))
result = []
for i in range(N) :
  temp = []
  for j in range(K) :
    sum = int(0)
    for k in range(M) :
      sum += A[i][k]*B[k][j]
    temp.append(sum)
  result.append(temp)
for i in result :
  print(*i)