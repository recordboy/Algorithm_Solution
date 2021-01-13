n, m = map(int, input().split())

card = []
result = 0

for i in range(n) :
  card.append(list(map(int, input().split())))
  minimum = min(card[i])
  result = max(minimum, result)

print(result)
  