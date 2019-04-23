st = set([0,5,6,7,8,9,10])
res = 0
for i in st:
    for j in st:
        if i==j: continue
        d = abs(i-j)
        if min(i,j)-d in st: continue
        tempRes = 2
        next = max(i, j)+d
        while next in st:
            tempRes += 1
            next += d
        res = max(res, tempRes)
print res
