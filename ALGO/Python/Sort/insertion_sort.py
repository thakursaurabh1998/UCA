from random import randint

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
    n = int(input("Enter the number of elements you want: "))
    ARR = [randint(0, 1000) for _ in range(n)]
    ARR = insertion_sort(ARR)
    print(ARR)
