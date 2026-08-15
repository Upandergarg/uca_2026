//my learnings-> Generi pointers, type casting, how to use fn pointers, writing code in c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//generic swap
void swap(void *arr, int i, int j,int size){
char* base= (char *)arr;
char* ele1= base+i*size;
char* ele2= base+j*size;

char* temp= malloc(size);

if(temp==NULL){
      printf("Memory allocation failed\n");
        exit(1);
}

memcpy(temp,ele1,size);
memcpy(ele1,ele2,size);
memcpy(ele2,temp,size);

free(temp);

}




//quick sort fn
void quickSort(void* arr, int low,int high, int (* comparator)(const void*,const void*),int size){
    if(low>=high) return;

    int pivot= low;
    int x=low;
    
    char *base= (char *)arr;

    for(int i=low; i<=high; i++){
        void *cur= base + i*size;
        void *pivotElement= base+ pivot*size;
        if(comparator(cur,pivotElement)<0){
            x++;
            swap(arr,i,x,size);
        }
    }
    swap(arr,pivot,x,size);

    quickSort(arr,low,x-1,comparator,size);
    quickSort(arr,x+1,high,comparator,size);

}



//comparators
int intComparator(const void *a, const void *b){
    int x= *(const int *)a;
    int y= *(const int*)b;

    if(x<y) return -1;
    if(x>y) return 1;

    return 0;
}


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

//student class
struct Student{
    int id;
    float cgpa;
    char* name;
};


int structComparator(const void*a, const void*b){
const struct Student x= *(const struct  Student *)a;
const struct  Student y= *(const struct  Student *)b;


    if (x.id < y.id)
        return -1;

    if (x.id > y.id)
        return 1;

    return 0;

}


//main fn
int main(){

    //for integer
    int arr[]= {5, 5, 9, 1, 10, 6};

    int n= sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

     printf("\n");

     quickSort(arr,0,n-1,intComparator,sizeof(int));

 printf("After integer sorting:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");



    //for float

    float arr1[]= {5.9, 2.1, 9.5, 1.3, 5.7, 6.2};

    int n1= sizeof(arr1)/sizeof(arr1[0]);

    for (int i = 0; i < n1; i++)
        printf("%.2f ", arr1[i]);

     printf("\n");

     quickSort(arr1,0,n1-1,floatComparator,sizeof(float));

 printf("After float sorting:\n");

    for (int i = 0; i < n1; i++)
        printf("%.2f ", arr1[i]);

    printf("\n\n");


    //for struct
 struct Student students[] =
    {
        {1749, 8.2, "upi"},
        {8475, 9.1, "ivar"},
        {7465, 7.5, "bjorn"},
        {8877, 8.8, "udi"}
    };
int sn= sizeof(students)/sizeof(students[0]);


    printf("Before student sorting:\n");

    for (int i = 0; i < sn; i++)
    {
        printf(
            "%d : %s : %.2f\n",
            students[i].id,
            students[i].name,
            students[i].cgpa
        );
    }
    quickSort(students,0,sn-1,structComparator,sizeof(struct Student));
   printf("\nAfter student sorting by ID:\n");

    for (int i = 0; i < sn; i++)
    {
        printf(
            "%d : %s : %.2f\n",
            students[i].id,
            students[i].name,
            students[i].cgpa
        );
    }


    return 0;
}

