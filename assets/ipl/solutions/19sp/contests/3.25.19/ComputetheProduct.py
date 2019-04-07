n = int(input())

N = 10**6
factors = [0] * (N + 1)
primes = []
tot = 1
M = 10**9
for i in range(2, N):
	if factors[i] == 0:
		factors[i] = i
		primes.append(i)
		tot = tot * i % M
		if len(primes) == n:
			break
	for j in primes:
		v = i * j
		if v >= N:
			break
		factors[v] = j
		if i % j == 0:
			break
print(tot)
