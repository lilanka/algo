import itertools

def number_of_sets(prices, g):
  all_sub_sets = []
  for x in prices:
    if x % g == 0:
      all_sub_sets.append(x)

  req = []
  n = len(all_sub_sets)
  masks = [1 << i for i in range(x)]
  for i in range(1 << n):
    st = [j for mask, j in zip(masks, all_sub_sets) if i & mask]
    if ((st not in req) and (st != [])):
      if (len(st) != 1) and (st.count(st[0]) == len(st)):
        continue
      else:
        req.append(st)
  return len(req);

if __name__ == "__main__":
  s = int(input()) # number of stock items
  stock_prices = [int(i) for i in input().split()]
  g = int(input()) # number of quaries
  quaries = []
  for _ in range(g):
    quaries.append(int(input()))

  for i in range(g):
    print(number_of_sets(stock_prices, quaries[i]))
