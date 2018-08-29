#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int comparator(int *i, int *j)
{
    int digit1 = 0, digit2 = 0;
    int n1 = *i, n2 = *j;
    while (n1)
    {
        digit1++;
        n1 /= 10;
    }
    while (n2)
    {
        digit2++;
        n2 /= 10;
    }
    int *arr1 = (int *)malloc(digit1 * sizeof(int));
    int *arr2 = (int *)malloc(digit2 * sizeof(int));
    n1 = *i;
    n2 = *j;
    int index = digit1 - 1;
    while (n1)
    {
        arr1[index--] = n1 % 10;
        n1 /= 10;
    }
    index = digit2 - 1;
    while (n2)
    {
        arr2[index--] = n2 % 10;
        n2 /= 10;
    }
    n1 = 0;
    n2 = 0;
    while (n1 < digit1 && n2 < digit2)
    {
        if (arr1[n1] < arr2[n2])
            return 1;
        else if (arr1[n1] > arr2[n2])
            return 0;
        n1++;
        n2++;
    }
    if (n1 < digit1)
    {
        n2 = 0;
        while (n1 < digit1 && n2 < digit2)
        {
            if (arr1[n1] == arr2[n2])
                return arr1[n1 - 1] < arr1[n1];
            if (arr1[n1] < arr2[n2])
                return 1;
            else if (arr1[n1] > arr2[n2])
                return 0;
            n1++;
            n2++;
        }
    }
    if (n2 < digit2)
    {
        n1 = 0;
        while (n1 < digit1 && n2 < digit2)
        {
            if (arr1[n1] == arr2[n2])
                return arr2[n2 - 1] < arr2[n2];
            if (arr1[n1] > arr2[n2])
                return 1;
            else if (arr1[n1] < arr2[n2])
                return 0;
            n1++;
            n2++;
        }
    }

    return 0;
}

void quickSort(int *arr, int l, int r)
{
    if (l == r)
        return;
    int i, j, temp;
    int random = r - 1;
    swap(arr, l, random);
    int pivot = l;
    int val = arr[l];
    // we will shift our pivot point virtually
    // without swapping the original values
    for (i = l; i < r; i++)
        if (comparator(arr + l, arr + i))
            swap(arr, i, ++pivot);

    swap(arr, l, pivot);
    quickSort(arr, l, pivot);
    quickSort(arr, pivot + 1, r);
}

char *toStr(int *arr, int n)
{
    int i;
    char *str = (char *)malloc(1000 * sizeof(char));
    char temp;
    int p = 0;
    int count;
    for (i = 0; i < n; i++)
    {
        count = 0;
        int n = arr[i];
        while (n)
        {
            count++;
            n /= 10;
        }
        n = arr[i];
        int c = count;
        while (n)
        {
            temp = '0' + n % 10;
            str[p + --count] = temp;
            n /= 10;
        }
        p += c;
    }
    str[p] = '\0';
    return str;
}

int main()
{
    // int arr[] = {3, 9, 4, 1, 11, 30, 33, 12, 35, 21, 2, 42, 359, 420, 873};
    int arr[] = {3, 30, 34, 5, 9};
    int n = 5;
    // int arr[] = {30, 3};
    // const int arr[] = {980, 674, 250, 359, 98, 969, 143, 379, 363, 106, 838, 923, 969, 880, 997, 664, 152, 329, 975, 377, 995, 943, 369, 515, 722, 302, 496, 124, 692, 993, 341, 785, 400, 113, 302, 563, 121, 230, 358, 911, 437, 438, 494, 599, 168, 866, 689, 444, 684, 365, 470, 176, 910, 204, 324, 657, 161, 884, 623, 814, 231, 694, 399, 126, 426};
    // const int arr[] = {931, 94, 209, 448, 716, 903, 124, 372, 462, 196, 715, 802, 103, 740, 389, 872, 615, 638, 771, 829, 899, 999, 29, 163, 342, 902, 922, 312, 326, 817, 288, 75, 37, 286, 708, 589, 975, 747, 743, 699, 743, 954, 523, 989, 114, 402, 236, 855, 323, 79, 949, 176, 663, 587, 322};
    // int n = 55;
    quickSort(arr, 0, n);
    printf("%s\n", toStr(arr, n));
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
