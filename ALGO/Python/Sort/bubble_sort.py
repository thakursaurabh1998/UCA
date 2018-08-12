def bubbleSort(arr):
    """Bubble Sort Algorithm"""
    for i in range(len(arr)):
        for j in range(len(arr)-1):
            if(arr[j+1] < arr[j]):
                arr[j+1], arr[j] = arr[j], arr[j+1]


if __name__ == '__main__':
    arr = [12, 34, 56, 23, 78, 38, 43, 89]
    bubbleSort(arr)
    for i in arr:
        print(i,end=" ")
