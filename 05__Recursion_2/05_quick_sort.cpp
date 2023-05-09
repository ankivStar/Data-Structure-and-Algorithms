#include <iostream>
using namespace std;

// si = starting index, li = last index, a = Given array
int partition(int *a, int si, int li)
{
    int pivot = *(a + si); // making the first element as pivot

    int c = si;
    int k = si + 1;
    while (k <= li) // finding out the correct positin of pivot
    {
        if (pivot > *(a + k++))
        {
            c++;
        }
    }

    // putting the pivot element at its right position
    int temp = *(a + c);
    *(a + c) = pivot;
    *(a + si) = temp;

    // putting all smaller element than pivot on left and greater or equal one on right.
    int i = si, j = li;
    while (i < c or j > c)
    {
        if (*(a + i) < pivot)
        {
            i++;
        }
        else if (*(a + j) >= pivot)
        {
            j--;
        }

        else
        {
            int temp = *(a + j);
            *(a + j) = *(a + i);
            *(a + i) = temp;
            i++;
            j--;
        }
    }

    return c; // returning the correct position of pivot
}

void quickSort(int *a, int si, int li)
{
    if (si < li)
    {
        int c = partition(a, si, li);

        quickSort(a, si, c - 1);
        quickSort(a, c + 1, li);
    }
}
int main()
{
    int a[12] = {0, 9, 4, 5, 2, 8, 5, 1, 0, 3, 7, 6};
    quickSort(a, 0, 11);

    for (int i = 0; i < 12; i++)
    {
        cout << *(a + i) << ", ";
    }

    return 0;
}