#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//generating array seciton
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

void generateAscendingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
}

void generateDescendingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

void copyArray(int source[], int destination[], int n)
{
    for (int i = 0; i < n; i++)
        destination[i] = source[i];
}


//selection sort section
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

double measureSelectionSort(int arr[], int n)
{
    clock_t start, end;

    start = clock();
    selectionSort(arr, n);
    end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}


//bubble sort section
void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double measureBubbleSort(int arr[], int n)
{
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

}




int main()
{
    srand(time(NULL));

    int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
    int iterations = 8;

    printf("Selection Sort Runtime Analysis\n\n");

    for (int i = 0; i < iterations; i++)
    {
        int n = sizes[i];

        int *original = (int *)malloc(n * sizeof(int));
        int *copy = (int *)malloc(n * sizeof(int));

        printf("Array Size = %d\n", n);


	//genrating random array for all sortings
        generateRandomArray(original, n);


        copyArray(original, copy, n);
        printf("Selectionsort (Random)   : %.2f ms\n", measureSelectionSort(copy, n));
 
        copyArray(original, copy, n);
        printf("Bubble Sort (Random)   : %.2f ms\n",measureBubbleSort(copy, n));





        //generating ascending array
        generateAscendingArray(original, n);

        copyArray(original, copy, n);
        printf("Selection sort (Ascending)  : %.2f ms\n", measureSelectionSort(copy, n));
     
        copyArray(original, copy, n);
        printf("Bubble Sort (Ascending)   : %.2f ms\n",measureBubbleSort(copy, n)); 
  




	//generating descending array 
        generateDescendingArray(original, n);

        copyArray(original, copy, n);
        printf("Selection Sort (Descending) : %.2f ms\n\n", measureSelectionSort(copy, n));


        copyArray(original, copy, n);
        printf("Bubble Sort (Descending)   : %.2f ms\n\n", measureBubbleSort(copy, n));




        free(original);
        free(copy);
    }

    return 0;
}
