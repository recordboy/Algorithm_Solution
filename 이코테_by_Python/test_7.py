a, b, k = map(int, input().split())

red = a//3
red_rest = a%3
black = b//2
black_rest = b%2

total = 0
rest = 0

if red > black :
    rest = (red-black)*3 + red_rest + black_rest
    red = black
else :
    rest = (black-red)*2 + red_rest + black_rest
    black = red

if rest >= k :
    total = red
else :
    k -= rest
    while k > 0 :
        red -= 1
        black -= 1
        k -= 5
        #print(red, black, k)
    total = red

print(total)