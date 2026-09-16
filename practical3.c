#include <stdio.h>

/* Function to swap two elements */
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

/* Bubble Sort */
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/* Selection Sort */
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }

        if (mini != i)
        {
            swap(&arr[i], &arr[mini]);
        }
    }
}

/* Insertion Sort */
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

/* Partition function for Quick Sort */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

/* Quick Sort */
void qs(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        qs(arr, low, pi - 1);
        qs(arr, pi + 1, high);
    }
}

/* Merge function for Merge Sort */
void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[100];

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

/* Merge Sort */
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

/* Function to print the array */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

/* Main function */
int main()
{
    int arr[100], n, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Your array: ");
    printArray(arr, n);

    printf("\n1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            bubblesort(arr, n);
            break;

        case 2:
            selectionsort(arr, n);
            break;

        case 3:
            insertionsort(arr, n);
            break;

        case 4:
            qs(arr, 0, n - 1);
            break;

        case 5:
            mergesort(arr, 0, n - 1);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("\nSorted array: ");
    printArray(arr, n);

    return 0;
}
```
