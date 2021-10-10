def is_survive(oscb, lmn, ki):
  o, c, s, b = oscb[0], oscb[1], oscb[2], oscb[3]
  l, m, n = lmn[0], lmn[1], lmn[2]
  k1, k2, k3, k4 = ki[0], ki[1], ki[2], ki[3]

  defence = 0 
  for day in range(m):
    if day >= n: # battle started
      if day == m-1:
        return 'VICTORY' if defence > 0 else 'DEFEAT'
      # soldires kill
      manpower = s*k2 + b*(k1/2)
      
      defence += manpower 

      # orc kills soldires
      defence -= k3 * (o-manpower) + k4 * c
      
    # builders build
    defence += b*k1 + s*(k1/2)

if __name__ == "__main__":
  """
  o: number of orcs in army
  c: number of catapults
  n: army attack of the day
  s: number of soliers
  b: number of builders

  l: helm's deep destroy limit
  m: number of days rohan to reinforce helms deep (n<=m)
  k1: builders build speed per day
  k2: speed of solder kills orcs 
  k3: speed of orc kills a soldiere
  k4: speed of catapults destroy the city
  """
  ocsb = [int(i) for i in input().split()] # O, C, S, B values
  lmn = [int(i) for i in input().split()]  # L, m, n values
  ki = [int(i) for i in input().split()]   # K values

  print(is_survive(ocsb, lmn, ki))
