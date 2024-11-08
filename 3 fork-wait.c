#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void bass(int arr[25], int n)  // Adjusted array size
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n Ascending Order \n");
    for (i = 0; i < n; i++)
        printf("\t%d", arr[i]);
    printf("\n\n\n");
}

void bdsc(int arr[25], int n)  // Adjusted array size
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n Descending Sorting \n\n");
    for (i = 0; i < n; i++)
        printf("\t%d", arr[i]);
    printf("\n\n\n");
}

void forkeg()
{
    int arr[25], n, i;
    printf("\nEnter the number of values in array: ");
    scanf("%d", &n);
    if (n > 25) {
        printf("Array size exceeds the limit of 25.\n");
        return;
    }
    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int pid = fork();
    if (pid == 0)
    {
        sleep(10);
        printf("\nChild process\n");
        printf("Child process id = %d\n", getpid());
        bdsc(arr, n);
        printf("\nElements Sorted Using Quick Sort");
        printf("\n");
        for (i = 0; i < n; i++)
            printf("%d,", arr[i]);
        printf("\b \nParent process id = %d\n", getppid());
        system("ps -x");
    }    
    else
    {
        printf("\nParent process\n");
        printf("\nParent process id = %d\n", getppid());
        bass(arr, n);
        printf("Elements Sorted Using Bubble Sort\n");
        for (i = 0; i < n; i++)
            printf("%d,", arr[i]);
        printf("\n\n\n");
    }
}    

int main()
{
    forkeg();
    return 0;
}