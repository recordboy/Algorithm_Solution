n, k = map(int, input().split())

calc = 0

while n != 1 :
  if n % k == 0 :
    calc += 1
    n = n // k
  else :
    calc += 1
    n = n - 1

print(calc)