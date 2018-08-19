from random import randint


def quick_sort(a):
    """
    Quick Sort function
    @param a : list of elements for quick sort
    """
    if len(a) <= 1:
        return a
    rand = randint(0, len(a)-1)
    a[0], a[rand] = a[rand], a[0]
    pivot = 0
    val = a[0]
    for i in enumerate(a):
        if val > a[i[0]]:
            pivot += 1
            a[i[0]], a[pivot] = a[pivot], a[i[0]]
    a[0], a[pivot] = a[pivot], a[0]
    left = quick_sort(a[:pivot])
    right = quick_sort(a[pivot+1:])
    return left + a[pivot:pivot+1] + right


if __name__ == '__main__':
    # ARR = [56, 23, 45, 54, 76, 98, 34, 54, 12, 1]
    n = int(input("Enter the number of elements you want: "))
    ARR = [randint(0, 1000) for _ in range(n)]
    ARR = quick_sort(ARR)
    print(ARR)
