# read n, x
n, x = [int(s) for s in input().split()]

# number of sad kids
m = 0
for i in range(n):
    a, d = input().split()
    d = int(d)
    if a == '+':
        x += d
    elif x >= d:
        x -= d
    else:
        m += 1

print(x, m)
