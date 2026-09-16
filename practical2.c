#include <stdio.h>

/* Function for Binary Search */
int binarysearch(int arr[], int l, int r, int target)
{
    if (l > r)
    {
        return -1;
    }

    int mid = l + ((r - l) / 2);

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarysearch(arr, l, mid - 1, target);
    }
    else
    {
        return binarysearch(arr, mid + 1, r, target);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target, z;

    printf("Enter target: ");
    scanf("%d", &target);

    z = binarysearch(arr, 0, n - 1, target);

    if (z != -1)
    {
        printf("%d is present at index %d", target, z);
    }
    else
    {
        printf("%d is not present", target);
    }

    return 0;
}
```
