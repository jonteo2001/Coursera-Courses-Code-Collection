def is_even(p):
    if set(p) != set(range(len(p))): return 'Error: Not Applicable'
    sign = 0 # sign = No. of transpositions modulo 2
    s = 0 # s = first s elements in the right places.
    n = len(p)
    for s in range(n):
        u = s; t = u;
        for u in range(s,n-1):
            u = u + 1
            if p[u] >= p[t]: continue

            elif p[u] < p[t]:
                tmp = p[u]; p[u] = p[t]; p[t] = tmp; #this signifies 1 transposition
                sign = 1 - sign
        s = s + 1
    if sign == 0: return True
    else: return False


print('Testing values........................................')
print('Permutation [1,2,3]:', is_even([1,2,3])) #Not Applicable

print('Permutation [0,2,1]:', is_even([0,2,1])) #False
print('Permutation [0,3,2,4,5,6,7,1,9,8]:', is_even([0,3,2,4,5,6,7,1,9,8])) #True
print('Permutation [8, 7, 9, 4, 6, 0, 1, 10, 5, 3, 2]:', is_even([8,7,9,4,6,0,1,10,5,3,2]))
#False
print('Permutation [3, 2, 0, 4, 5, 1, 6]:', is_even([3, 2, 0, 4, 5, 1, 6])) #False
