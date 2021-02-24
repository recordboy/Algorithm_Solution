N = int(input())
paper = []
blue = int() 
white = int()

# 색종이 입력 함수
def getPaper(array, size) :
  for i in range(size) :
    array.append(list(map(int, input().split())))

# 색종이를 카운트하는 재귀 함수
def cntPaper(arr, size, row, col) :
  global blue, white
  cnt_blue = bool(False)
  cnt_white = bool(False)
  if size == 1 :
    if arr[row][col] == 1 :
      blue += 1
    else :
      white += 1
    return
  b = []
  for i in arr[row:row+size] :
    b.append(i[col:col+size])
  if b == [[0]*size]*size :
    cnt_white = True
  if b == [[1]*size]*size :
    cnt_blue = True
  if cnt_white :
    white += 1
  elif cnt_blue :
    blue += 1
  elif (not cnt_blue) or (not cnt_white) :
    cntPaper(arr, size//2, row, col)
    cntPaper(arr, size//2, row+size//2, col)
    cntPaper(arr, size//2, row, col+size//2)
    cntPaper(arr, size//2, row+size//2, col+size//2)

getPaper(paper, N)
cntPaper(paper, N, 0, 0)

print(white, blue, sep = "\n")