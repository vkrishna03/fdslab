#include <stdio.h>

void main()
{
    int n, arr[10], temp;
    int i, j;

    printf("Enter no of elements:\t");
    scanf("%d", &n);

    printf("Enter %d elements:\t", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

    printf("Elements in the sorted array are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}