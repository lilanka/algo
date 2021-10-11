def model(n):
  n_s, n_h = 3, 5
  if n < n_s:
    return "Invalid Model Name"
  for i in range(n):
    if n % n_h == 0:
      return "H"*n
    if n % n_s == 0:
      return "S"*n
    if ((n-i) % n_s == 0 and (i % n_h == 0)):
      if n-i < i:
        return "S"*(n-i) + "H"*(n-i)
      return "S"*(n-i) + "H"*(i)
  return "Invalid Model Name"

if __name__ == "__main__":
  digits = []
  
  for _ in range(5):
    digits.append(int(input()))

  for x in digits:
    if (x >= 1 and x <= 999):
      print(model(x))
