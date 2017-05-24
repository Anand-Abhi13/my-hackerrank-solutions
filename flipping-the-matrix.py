T = int(input())
for t in range(T):
    n=int(input())
    M=[list(map(int,input().split())) for i in range(2*n)]
    for i in range(n):
        for j in range(n):
            M[i][j]=max(M[i][j],M[2*n-i-1][j],M[2*n-i-1][2*n-j-1],M[i][2*n-j-1])
    s=0;
    for x in M[0:n]:
        s+=sum(x[0:n])
    print(s)
