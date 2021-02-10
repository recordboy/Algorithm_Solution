l, p, c = map(int, input().split())
pos = list(map(int, input().split()))

def decide(p, size) :
    n = 0
    count = 0
    for i in pos :
        n += i
        if n >= size :
            count += 1
            n = 0
    if count >= p+1:
        return True
    else :
        return False

