def op():
  f, d, aim = 0, 0, 0
  with open("aofc2.txt", "r") as file:
    for line in file:
      data = line.strip().split()
      amount = int(data[1])
      if 'forward' == data[0]:
        f += amount
        d += aim*amount 
      elif 'down' == data[0]:
        #d += amount 
        aim += amount
      else:
        #d -= amount 
        aim -= amount
  return f*d

print(op())
