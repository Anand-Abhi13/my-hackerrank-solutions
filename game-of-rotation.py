#https://www.hackerrank.com/challenges/game-of-rotation

n = int(input())
A = [int(s) for s in input().split()]
best = pmean = sum(i*v for i,v in enumerate(A, 1))
Sum = sum(A)
for i in A:
    pmean += n*i - Sum
    best = max(best, pmean)
print(best)
