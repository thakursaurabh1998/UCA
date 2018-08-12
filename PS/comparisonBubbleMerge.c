#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
            if (arr[j + 1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

static int aux[1000000];

void merge(int *arr, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
        if (arr[i] < arr[j])
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    while (j <= r)
        aux[k++] = arr[j++];
    while (i <= mid)
        aux[k++] = arr[i++];
    for (i = 0; i < k; i++)
        arr[l + i] = aux[i];
}

void mergeSort(int *arr, int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    aux[n];
    int *arr1 = (int *)malloc(sizeof(int) * n);
    int *arr2 = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        arr2[i] = arr1[i] = rand();
    for (i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    struct timeval tv1;
    struct timezone tz1;
    gettimeofday(&tv1, &tz1);
    mergeSort(arr1, 0, n - 1);
    struct timeval tv2;
    struct timezone tz2;
    gettimeofday(&tv2, &tz2);
    printf("start:%lld stop:%lld diff:%lld\n", (long long)tv1.tv_sec, (long long)tv2.tv_sec, (long long)tv2.tv_sec - (long long)tv1.tv_sec);
    gettimeofday(&tv1, &tz1);
    // bubbleSort(arr2, n);
    gettimeofday(&tv2, &tz2);
    printf("start:%lld stop:%lld diff:%lld\n", (long long)tv1.tv_sec, (long long)tv2.tv_sec, (long long)tv2.tv_sec - (long long)tv1.tv_sec);
    // printf("\n");
    // for (i = 0; i < n; i++)
    //     printf("%d ", arr2[i]);
    free(arr1);
    free(arr2);
    arr1=NULL;
    arr2=NULL;

    return 0;
}