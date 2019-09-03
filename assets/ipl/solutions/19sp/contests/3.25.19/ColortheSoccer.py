mod = 1000000007

n = int(input())


t = (20 * n ** 12 + 24 * n ** 8 + n ** 32 + 15 * n ** 16) // 60
print(t % mod)
