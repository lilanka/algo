import sys

def read_file():
  with open("aofc1.txt", "r") as f:
    data = [int(line.strip()) for line in f]
  return data

def op_p1():
  x = 0
  data = read_file()
  prev = data[0]
  for curr in data[1:]:
    if curr > prev:
      x+=1
    prev = curr
  print(x)

def op_p2(data, prev=0, i=0, x=0, length=0):
  if i == 0:
    length = len(data)
    sys.setrecursionlimit(length+100)

  if i > length-3:
    print(x)
    return 
  curr = sum(data[i:i+3])
  if (curr > prev) and i > 0:
    x+=1
  i+=1
  return(op_p2(data, curr, i, x, length))

#op_p1()
op_p2(read_file())
