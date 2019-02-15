def count(diff, remain):
	if diff > remain:
		return 0
	if remain == 0:
		return 1
	cnt = 0
	if diff > 0:
		cnt += count(diff - 1, remain - 1)
	cnt += count(diff + 1, remain - 1)
	return cnt

print(count(0, int(input())))
