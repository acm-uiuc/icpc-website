n = int(input())
a = list(map(int, input().split()))
dp = [0] * n
mf = 0
for i in range(n):
	mx = 0
	for j in range(i):
		if a[i] > a[j]:
			mx = max(mx, dp[j])
	dp[i] = mx + 1
	mf = max(mf, dp[i])
print(mf)
