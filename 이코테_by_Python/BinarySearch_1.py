n = int(input())
store = list(map(int, input().split()))
m = int(input())
customer = list(map(int, input().split()))

store.sort()

def binarySearch(array, start, end, target) :
    while start <= end :
        mid = (start+end)//2
        if array[mid] > target :
            end = mid-1
        elif array[mid] < target :
            start = mid+1
        else :
            return mid
    return None

for i in range(m) :
    target = customer[i]
    result = binarySearch(store, 0, n-1, target)
    if result == None :
        print('no', end = ' ')
    else :
        print('yes', end = ' ')
