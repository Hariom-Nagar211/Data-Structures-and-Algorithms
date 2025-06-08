from itertools import combinations 

def f(arr):
    n = len(arr)
    stt = set()
    arr.sort()

    for i in range(n):
        j = i+1
        k = n-1
        while j<k:
            sum_ = arr[i] + arr[j] + arr[k]
            if sum_ == 0:
                stt.add((arr[i], arr[j], arr[k]))
                j += 1
                k -= 1

            elif sum_ < 0:
                j += 1

            else:
                k -= 1

    for it in stt:
        print(' '.join(str(x) for x in it))


arr = [-1,0,1,4,3,-2,5,6,0,3]
f(arr)


