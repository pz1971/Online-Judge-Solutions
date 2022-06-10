from sys import stdin

dp = [[0, 0] for i in range(2005)]
ar = (6, 2, 5, 5, 4, 5, 6, 3, 7, 6)

def func(n, starting):
    if n < 2:
        return 0
    if dp[n][starting] != 0:
        return dp[n][starting]
    ret = 0
    if starting == 1 and n >= ar[0]:
        ret = ret + 1
    for i in range(starting, len(ar)):
        if ar[i] <= n:
            ret = ret + 1 + func(n - ar[i], 0)
    dp[n][starting] = ret
    return ret

for inp in stdin:
    if inp == '':
        break
    n = int(inp)
    print(func(n, 1))
