t=int(input())
for i in range(t):
    n=int(input())
    if n==1:
        print(2)
        break
    ctr =0
    aL = []
    bL = []
    for i in range(n):
        a,b=map(int,input().split())
        if a not in aL:
            if b not in bL:
                ctr+=2
            else:
                ctr+=1
        else:
            if b not in bL:
                ctr+=1
            else:
                pass
    print(ctr)