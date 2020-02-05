# read the integer n, note indices start with 0 in python
n = int(input()) - 1
# generate a list with 500 strings ["1", "2", "3", ..., "500"]
v = [str(i) for i in range(1, 500)]
# concatenate all the strings together and we get "1234567891011..."
s = ''.join(v)
print(s[n])

# one line solution
#print(''.join([str(i) for i in range(1, 500)])[int(input()) - 1])
