# step 1: read the three digits
a, b, c = input().split()

# step 2: compute the 3-digit number
n = int(a)*100 + int(b)*10 + int(c)

# step 3: check if the 3-digit number is divisible by 4
print("YES" if n % 4 == 0 else "NO")
