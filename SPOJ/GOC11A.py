t = int(input())
while t > 0:
    t -= 1
    S = input()
    T = ''
    for i in S:
        if i in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
            T *= int(i)
        else:
            T += i
    q = int(input())
    while q > 0:
        q -= 1
        p = int(input())
        if(p > len(T)):
            print(-1)
        else:
            print(T[p-1])
