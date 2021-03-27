import sys
import os
import numpy as np
from subprocess import Popen, PIPE

p = Popen(['./a.out'], shell=True, stdout=PIPE, stdin=PIPE)

n = int(sys.argv[1])
arr = list(np.random.permutation(n))
for i in range(len(arr)):
    arr[i] += 1

# print(arr)

cntQueries = 0


def getMedian(x, y, z):
    global cntQueries
    cntQueries += 1
    xIndex = arr.index(x)
    yIndex = arr.index(y)
    zIndex = arr.index(z)

    l = [xIndex, yIndex, zIndex]
    l.sort()

    if l[1] == xIndex:
        return x
    elif l[1] == yIndex:
        return y
    return z


def isEqual(l1, l2):
    assert len(l1) == len(l2)
    n = len(l1)
    bad = False
    for i in range(n):
        if l1[i] != l2[i]:
            bad = True
            break
    if not bad:
        return True
    l2 = l2[::-1]
    for i in range(n):
        if l1[i] != l2[i]:
            return False
    return True


p.stdin.write(bytes(f"1 {n} 1000\n", 'UTF-8'))
p.stdin.flush()

while True:
    queryAsked = p.stdout.readline().strip()
    if len(queryAsked.split()) == n:
        l = [int(x) for x in queryAsked.split()]
        print('arr was', arr)
        print('got res', l)
        print(isEqual(arr, l))
        break
    x, y, z = map(int, queryAsked.split())
    print('asked', x, y, z)
    median = getMedian(x, y, z)
    p.stdin.write(bytes(str(median) + '\n', 'UTF-8'))
    p.stdin.flush()
    print('answered', median)

print('asked total', cntQueries)
