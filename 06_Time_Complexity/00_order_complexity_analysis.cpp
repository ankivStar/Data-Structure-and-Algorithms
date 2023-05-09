#include <sys/time.h>
#include <iostream>
using namespace std;

long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void merge(int arr[], int start, int mid, int end)
{
    int temp[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid and j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    if (i <= mid)
    {
        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }
    }

    if (j <= end)
    {
        while (j <= end)
        {
            temp[k++] = arr[j++];
        }
    }
    k = 0;
    for (int l = start; l <= end; l++)
    {
        arr[l] = temp[k++];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (end + start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void selectionSort(int a[], int n)
{
    for (int j = 0; j < n-1; j++)
    {
        int min = a[j];
        int pos = j;
        for (int i = j + 1; i < n; i++)
        {
            if(a[i] < min)
            {
                min = a[i];
                pos = i;
            }
        }

        int temp = a[j];
        a[j] = min;
        a[pos] = temp;
    }
}

int main()
{
    for (int n = 10; n <= 10000; n = n * 10)
    {
        int *arr = new int[n];
        long starttime, endtime;

        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }

        starttime = getTimeinMicroSeconds();
        mergeSort(arr, 0, n - 1);
        //selectionSort(arr, n);
        endtime = getTimeinMicroSeconds();

        cout << "Merge Sort n = " << n << " time = " << (endtime - starttime) << endl;
        delete [] arr;
    }
    return 0;
}