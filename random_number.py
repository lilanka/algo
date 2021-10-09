def contain_d(lst, D):
  for i in D:
    if i in lst:
      return True
  return False

def generator(A, B, C, D):
  numbers = range(A, B+1)
  if (contain_d(numbers, D)):
    return numbers[C-1]
  return "DOES NOT EXIST"

if __name__ == "__main__":
  x = input().split()
  x = [int(i) for i in x]
  sub = []
  for _ in range(x[3]):
    sub.append(int(input()))
  print(generator(x[0], x[1], x[2], sub))
