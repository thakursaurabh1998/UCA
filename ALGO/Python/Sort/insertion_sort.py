def insertion_sort(a):
    """
    Insertion sort algorithm function
    @param a : list to sort
    """
    for i, val in enumerate(a):
        index = i
        for j in range(i-1, -1, -1):
            if val < a[j]:
                index = j
        temp = a.pop(i)
        a.insert(index, temp)
    return a


if __name__ == '__main__':
    ARR = [56, 23, 45, 54, 76, 98, 34, 54, 12, 1]
    ARR = insertion_sort(ARR)
    print(ARR)
