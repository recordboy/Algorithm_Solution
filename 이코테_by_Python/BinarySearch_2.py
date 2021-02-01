n, m = map(int, input().split())
length = list(map(int, input().split()))

lim = max(length)

def binarySearch(array, start, end) :
    result = 0
    while start <= end :
        total = 0
        mid = (start+end)//2
        for i in array :
            if mid < i :
                total += i-mid
        if total >= m :
            result = mid
            start = mid+1
        else :
            end = mid-1
    return result

print(binarySearch(length, 0, lim))
        