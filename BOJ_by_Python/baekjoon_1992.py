N = int(input())
tree = []

for i in range(N) :
  tree.append(list(input()))

def getQuadTree(arr, size) :
  zero_total = [["0"]*size]*size
  one_total = [["1"]*size]*size
  zero_sub = [["0"]*(size//2)]*(size//2)
  one_sub = [["1"]*(size//2)]*(size//2)
  if arr == zero_total :
    print(0)
  elif arr == one_total :
    print(1)
  else :
    print("(", end = '')
    sub_tree1 = []
    sub_tree2 = []
    sub_tree3 = []
    sub_tree4 = []
    for i in range(4) :
      if i == 0 :
        for sub_arr in arr[0:size//2] :
          sub_tree1.append(sub_arr[0:size//2])
      elif i == 1 :
        for sub_arr in arr[0:size//2] :
          sub_tree2.append(sub_arr[size//2:size])
      elif i == 2 :
        for sub_arr in arr[size//2:size] :
          sub_tree3.append(sub_arr[0:size//2])
      elif i == 3 :
        for sub_arr in arr[size//2:size] :
          sub_tree4.append(sub_arr[size//2:size])
    if zero_sub == sub_tree1 :
      print("0", end = '')
    elif one_sub == sub_tree1 :
      print("1", end = '')
    else :
      getQuadTree(sub_tree1, size//2)
    if zero_sub == sub_tree2 :
      print("0", end = '')
    elif one_sub == sub_tree2 :
      print("1", end = '')
    else :
      getQuadTree(sub_tree2, size//2)
    if zero_sub == sub_tree3 :
      print("0", end = '')
    elif one_sub == sub_tree3 :
      print("1", end = '')
    else :
      getQuadTree(sub_tree3, size//2)
    if zero_sub == sub_tree4 :
      print("0", end = '')
    elif one_sub == sub_tree4 :
      print("1", end = '')
    else :
      getQuadTree(sub_tree4, size//2)
    print(")", end = '')

getQuadTree(tree, N)
    
    

  