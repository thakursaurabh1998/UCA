def binary_search(collection, search):
    """Binary search algorithm"""
    if not collection:
        return
    mid = len(collection)//2
    if len(collection) == 1 and collection[mid] != search:
        return 'not found'
    if collection[mid] == search:
        return collection[mid]
    if collection[mid] > search:
        return binary_search(collection[:mid], search)
    else:
        return binary_search(collection[mid:], search)


if __name__ == '__main__':
    arr = [23, 34, 63, 78, 12, 45, 21, 80]
    arr.sort()
    print(arr)
    print(binary_search(arr, 23))
