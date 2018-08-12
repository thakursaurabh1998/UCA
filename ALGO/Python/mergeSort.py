def merge(a, left, mid, right):
    i = left
    j = mid+1
    aux = []
    while i <= mid and j <= right:
        if a[i] < a[j]:
            aux.append(a[i])
            i += 1
        else:
            aux.append(a[j])
            j += 1
    while i <= mid:
        aux.append(a[i])
        i += 1
    while j <= right:
        aux.append(a[j])
        j += 1
    a = a[:left] + aux + a[right+1:]
    # print(aux)
    return a


def merge_sort(a, left, right):
    if left == right:
        return a
    mid = (left+right)//2
    a = merge_sort(a, left, mid)
    a = merge_sort(a, mid+1, right)
    return merge(a, left, mid, right)


if __name__ == '__main__':
    arr = [12, 34, 56, 23, 78, 38, 43, 89]
    arr = merge_sort(arr, 0, len(arr)-1)
    print(arr)
