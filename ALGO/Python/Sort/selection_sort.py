from random import randint


def selection_sort(a):
    """
    Selection Sort algorithm function
    @param a : list to sort
    """
    for i in enumerate(a):
        min_index = a[i[0]:].index(min(a[i[0]:]))
        min_index += i[0]
        a[i[0]], a[min_index] = a[min_index], a[i[0]]
    return a


if __name__ == '__main__':
    n = int(input("Enter the number of elements you want: "))
    ARR = [randint(0, 1000) for _ in range(n)]
    ARR = selection_sort(ARR)
    print(ARR)
