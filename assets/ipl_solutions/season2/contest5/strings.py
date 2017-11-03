n = int(input())
s = [input() for i in range(n)]
m = len(s[0])

inf = 1000000000

r = min([i + sum([min([k if s[0][i:] + s[0][:i] == s[j][k:] + s[j][:k] else inf
                       for k in range(m)]) 
                  for j in range(1, n)]) 
         for i in range(m)])

print(r if r < inf else -1)
