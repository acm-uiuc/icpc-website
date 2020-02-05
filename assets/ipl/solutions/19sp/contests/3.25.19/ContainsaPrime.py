inp = list(map(int, input().split()))
n = inp[0]
assert len(inp) == n + 1
f = False
for v in inp[1:]:
  for i in range(2, v + 1):
    if i * i > v:
      f = True
      break
    if v % i == 0:
      break
print("YES" if f else "NO")
