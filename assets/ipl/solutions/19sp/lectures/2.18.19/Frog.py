n = int(input())
h = list(map(int, input().split()))
dist = [10**9] * n
dist[0] = 0
for i in range(0, n):
	if i + 1 < n:
		dist[i + 1] = min(dist[i + 1], dist[i] + abs(h[i + 1] - h[i]))
	if i + 2 < n:
		dist[i + 2] = min(dist[i + 2], dist[i] + abs(h[i + 2] - h[i]))
print(dist[n - 1])
