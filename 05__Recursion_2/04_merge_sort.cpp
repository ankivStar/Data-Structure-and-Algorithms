#include <iostream>
using namespace std;

void merge(int *a, int si, int mid, int li) // merging the array
{
    int b[li - si + 1];
    int k = 0;
    int i = si;
    int j = mid + 1;
    while (i <= mid and j <= li)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }

    while (j <= li)
    {
        b[k++] = a[j++];
    }

    for (i = si; i <= li; i++)
    {
        a[i] = b[i - si];
    }
}

void mergeSort(int *a, int si, int li) // splitting the array
{
    int mid;
    if (si < li)
    {
        mid = (si + li) / 2;
            
        mergeSort(a, si, mid);
        mergeSort(a, mid + 1, li);

        merge(a, si, mid, li);
    }
}

int main()
{
    int a[10] = {9, 4, 2, 8, 5, 1, 0, 3, 7, 6};
    mergeSort(a, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << *(a + i) << ", ";
    }
    return 0;
}