
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n){
	for (int i = 0; i < n-1; i++) {
	  for (int j = 0; j < n-i-1; j++) {
             if (arr[j] > arr[j+1]) {
		int temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j+1] = temp;
	     }
	  }
	}
}
void generateNumbers(int arr[],int n){
	for (int i = 0; i < n; i++){
          arr[i] = rand() % 100000;
	}
}
int main(){
	srand(time(NULL));
        int size1=40000;
	int size2=80000;
	int* arr1= (int *) malloc(size1 * sizeof(int));
	int* arr2= (int *) malloc(size2 * sizeof(int));

	generateNumbers(arr1,size1);
	clock_t start = clock();
	bubbleSort(arr1,size1);
	clock_t end = clock();

	double time = ((double)end-start) / CLOCKS_PER_SEC;

	generateNumbers(arr2,size2);
        clock_t start2 = clock();
        bubbleSort(arr2,size2);
        clock_t end2 = clock();

        double time2 = ((double)end2-start2) / CLOCKS_PER_SEC;
        
	printf("\n%f\n",time2/time);

	return 0;
}
