#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct 
struct Student
{
    int id;
    float cgpa;
    char *name;
};

//generic swap

void swap(void *arr, int i, int j, int size)
{
    char *base = (char *)arr;

    char *element1 = base + i * size;
    char *element2 = base + j * size;

    char *temp = malloc(size);

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    memcpy(temp, element1, size);
    memcpy(element1, element2, size);
    memcpy(element2, temp, size);

    free(temp);
}

//generic heapify
void heapify(void *arr, int n, int i, int size, int (*comparator)(const void *, const void *))
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    char *base = (char *)arr;

    if (left < n)
    {
        void *leftElement = base + left * size;
        void *largestElement = base + largest * size;

        if (comparator(leftElement, largestElement) > 0)
        {
            largest = left;
        }
    }
    if (right < n)
    {
        void *rightElement = base + right * size;
        void *largestElement = base + largest * size;

        if (comparator(rightElement, largestElement) > 0)
        {
            largest = right;
        }
    }

    if (largest != i)
    {
        swap(arr, i, largest, size);

        heapify(arr, n, largest, size, comparator);
    }
}

//generic heap sort

void heapSort(
    void *arr,
    int n,
    int size,
    int (*comparator)(const void *, const void *))
{


    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, size, comparator);
    }


    for (int i = n - 1; i > 0; i--)
    {
        swap(arr, 0, i, size);

        heapify(arr, i, 0, size, comparator);
    }
}

//Integer Comparator

int intComparator(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

//float compare
int floatComparator(const void *a, const void *b)
{
    float x = *(const float *)a;
    float y = *(const float *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

//struct compare
int studentComparator(const void *a, const void *b)
{
    const struct Student *x = (const struct Student *)a;
    const struct Student *y = (const struct Student *)b;

    if (x->id < y->id)
        return -1;

    if (x->id > y->id)
        return 1;

    return 0;
}


int main()
{
   //integer
    int arr[] = {5, 5, 9, 1, 10, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before integer sorting:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    heapSort(arr, n, sizeof(int), intComparator);

    printf("\nAfter integer sorting:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

//float
    float arr1[] = {5.9, 2.1, 9.5, 1.3, 5.7, 6.2};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Before float sorting:\n");

    for (int i = 0; i < n1; i++)
        printf("%.2f ", arr1[i]);

    heapSort(arr1, n1, sizeof(float), floatComparator);

    printf("\nAfter float sorting:\n");

    for (int i = 0; i < n1; i++)
        printf("%.2f ", arr1[i]);

    printf("\n\n");

    //struct
    struct Student students[] =
    {
        {1749, 8.2, "upi"},
        {8475, 9.1, "ivar"},
        {7465, 7.5, "bjorn"},
        {8877, 8.8, "udi"}
    };

    int sn = sizeof(students) / sizeof(students[0]);

    printf("Before student sorting:\n");

    for (int i = 0; i < sn; i++)
    {
        printf("%d : %s : %.2f\n",
               students[i].id,
               students[i].name,
               students[i].cgpa);
    }

    heapSort(
        students,
        sn,
        sizeof(struct Student),
        studentComparator
    );

    printf("\nAfter student sorting by ID:\n");

    for (int i = 0; i < sn; i++)
    {
        printf("%d : %s : %.2f\n",
               students[i].id,
               students[i].name,
               students[i].cgpa);
    }

    return 0;
}