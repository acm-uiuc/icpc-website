def gcd(a, b):
	return gcd(b, a % b) if b != 0 else a

mod = 10 ** 9 + 7
N = 2

def matrix_multiplication(matrix_1, matrix_2):
	result = [[0 for _ in range(N)] for _ in range(N)]
	for i in range(N):
		for j in range(N):
			for k in range(N):
				result[i][j] = (result[i][j] + matrix_1[i][k] * matrix_2[k][j]) % mod
	return result

def matrix_power(matrix, power):
	if power == 1:
		return matrix
	if power % 2 == 0:
		return matrix_power(matrix_multiplication(matrix, matrix), power // 2)
	return matrix_multiplication(matrix, matrix_power(matrix_multiplication(matrix, matrix), power // 2))

def get_nth(n):
	if n == 1 or n == 2:
		return 1
	matrix = [[0, 1], [1, 1]]
	matrix = matrix_power(matrix, n - 2)
	result = (matrix[1][0] + matrix[1][1]) % mod
	return result

n = int(input())
indices = list(map(int, input().split()))
real_gcd = indices[0]
for ind in indices:
	real_gcd = gcd(real_gcd, ind)
print(get_nth(real_gcd))