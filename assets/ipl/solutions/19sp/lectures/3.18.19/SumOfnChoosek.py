mod = 1000000007
n = int(input()) + 1
tot = 1
for i in range(n):
  tot *= 2
  tot %= mod
print((tot + mod - 1) % mod)
