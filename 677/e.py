import math

n = int(input())

half = n//2

# perms = math.factorial(half)

res = math.factorial(n-1)//half

print(res)
