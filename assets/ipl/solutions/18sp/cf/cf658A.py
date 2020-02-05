# example input "6 2 -5"
#   input(): read the line "6 2 -5"
#   split(): split the line by spaces into list ["6", "2", "-5"]
#   [int(s) ... ]: list comprehension, convert the strings to integers
#                  ["6", "2", "-5"] => [6, 2, -5]
#   n, a, b = [6, 2, -5]: unpack the list and assign values to the variables
n, a, b = [int(s) for s in input().split()]

# it is more convinient to deal with indices starting with 0
r = (a - 1 + b) % n
if r < 0:
    r += n
# add 1 back so the indices start with 1
print(r + 1)
