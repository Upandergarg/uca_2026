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

//insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

double measureInsertionSort(int arr[], int n)
{
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}


//quick sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double measureQuickSort(int arr[], int n)
{
    clock_t start = clock();

    quickSort(arr, 0, n - 1);

    clock_t end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}

//merge sort 
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

double measureMergeSort(int arr[], int n)
{
    clock_t start = clock();

    mergeSort(arr, 0, n - 1);

    clock_t end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}

//heap sort

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

double measureHeapSort(int arr[], int n)
{
    clock_t start = clock();

    heapSort(arr, n);

    clock_t end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}


int main()
{
    srand(time(NULL));

    int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
    int iterations = 8;

    printf("Sorting  Runtime Analysis\n\n");

    for (int i = 0; i < iterations; i++)
    {
        int n = sizes[i];

        int *original = (int *)malloc(n * sizeof(int));
        int *copy = (int *)malloc(n * sizeof(int));

        printf("\n\n");
        printf("Array Size : %d\n", n);
        printf("\n");


	//genrating random array for all sortings
	printf("\nRandom Array\n");
        generateRandomArray(original, n);


        copyArray(original, copy, n);
        printf("Selectionsort : %.2f ms\n", measureSelectionSort(copy, n));
 
        copyArray(original, copy, n);
        printf("Bubble Sort : %.2f ms\n",measureBubbleSort(copy, n));

        copyArray(original, copy, n);
        printf("Insertion Sort  : %.2f ms\n", measureInsertionSort(copy, n));

	copyArray(original, copy, n);
        printf("Quick Sort  : %.2f ms\n", measureQuickSort(copy, n));

	copyArray(original, copy, n);
        printf("Merge Sort  : %.2f ms\n", measureMergeSort(copy, n));


	copyArray(original, copy, n);
        printf("Heap Sort   : %.2f ms\n", measureHeapSort(copy, n));


	printf("\nAscending Array\n");
        //generating ascending array
        generateAscendingArray(original, n);

        copyArray(original, copy, n);
        printf("Selection sort  : %.2f ms\n", measureSelectionSort(copy, n));
     
        copyArray(original, copy, n);
        printf("Bubble Sort   : %.2f ms\n",measureBubbleSort(copy, n)); 
  
        copyArray(original, copy, n);
        printf("Insertion Sort   : %.2f ms\n", measureInsertionSort(copy, n));

        copyArray(original, copy, n);
        printf("Quick Sort   : %.2f ms\n", measureQuickSort(copy, n));

	copyArray(original, copy, n);
        printf("Merge Sort  : %.2f ms\n", measureMergeSort(copy, n));

	copyArray(original, copy, n);
        printf("Heap Sort    : %.2f ms\n", measureHeapSort(copy, n));
	printf("\nDescending Array\n");


	//generating descending array 
        generateDescendingArray(original, n);

        copyArray(original, copy, n);
        printf("Selection Sort  : %.2f ms\n", measureSelectionSort(copy, n));


        copyArray(original, copy, n);
        printf("Bubble Sort    : %.2f ms\n", measureBubbleSort(copy, n));

	copyArray(original, copy, n);
        printf("Insertion Sort   : %.2f ms\n", measureInsertionSort(copy, n));

        copyArray(original, copy, n);
        printf("Quick Sort   : %.2f ms\n", measureQuickSort(copy, n));


	copyArray(original, copy, n);
        printf("Merge Sort    : %.2f ms\n", measureMergeSort(copy, n));


	copyArray(original, copy, n);
        printf("Heap Sort    : %.2f ms\n", measureHeapSort(copy, n));


        free(original);
        free(copy);
    }

    return 0;
}

