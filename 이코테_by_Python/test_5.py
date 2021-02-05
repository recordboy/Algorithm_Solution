import sys
input = sys.stdin.readline

num = list(input().strip())
length = len(num)

array = [0 for i in range(length+1)]

array[0] = 1
array[1] = 1

if num[0] == '0' :
    pass
else :
    for i in range(2, length+1) :
        if 0 < int(num[i-1]) :
            array[i] += array[i-1]
        n = int(num[i-1]) + 10*int(num[i-2])
        if 10 <= n <= 26 :
            array[i] += array[i-2]
    print(array[length]%1000009)