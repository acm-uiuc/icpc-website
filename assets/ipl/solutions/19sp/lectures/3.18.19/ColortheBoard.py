n = int(input())

mod = 1000000007

n = n * n

def pow(b):
	q = 1
	for _ in range(b):
		q = q * 2 % mod
	return q

a1 = pow(4 * n - 2) + pow(n - 1) + pow(2 * n - 2)
print(a1 % mod)
