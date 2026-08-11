 import java.util.Random;

class heapSort {

    static void heapify(int arr[], int n, int i) {
        int Largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[Largest]) {
            Largest = left;
        }

        if (right < n && arr[right] > arr[Largest]) {
            Largest = right;
        }

        if (Largest != i) {
            int swap = arr[i];
            arr[i] = arr[Largest];
            arr[Largest] = swap;

            heapify(arr, n, Largest);
        }
    }

    static void heapSort(int[] arr) {
        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    static void generateRandomArray(int arr[]) {
        Random random = new Random();

        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(100000);
        }
    }

    static void generateAscendingArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i + 1;
        }
    }

    static void generateDescendingArray(int arr[]) {
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
    }

    static void copyArray(int source[], int destination[]) {
        for (int i = 0; i < source.length; i++) {
            destination[i] = source[i];
        }
    }

    static double measureHeapSort(int arr[]) {
        long start = System.nanoTime();

        heapSort(arr);

        long end = System.nanoTime();

        return (end - start) / 1000000.0;
    }

    public static void main(String[] args) {

        int sizes[] = {
            8000, 12000, 16000, 20000,
            24000, 28000, 32000, 36000
        };

        System.out.println("Heap Sort Runtime Analysis");

        for (int i = 0; i < sizes.length; i++) {

            int n = sizes[i];

            int original[] = new int[n];
            int copy[] = new int[n];

            System.out.println("\nArray Size : " + n);

            System.out.println("\nRandom Array");

            generateRandomArray(original);

            copyArray(original, copy);
            System.out.printf("Heap Sort : %.2f ms\n",
                    measureHeapSort(copy));


            System.out.println("\nAscending Array");

            generateAscendingArray(original);

            copyArray(original, copy);
            System.out.printf("Heap Sort : %.2f ms\n",
                    measureHeapSort(copy));


            System.out.println("\nDescending Array");

            generateDescendingArray(original);

            copyArray(original, copy);
            System.out.printf("Heap Sort : %.2f ms\n",
                    measureHeapSort(copy));
        }
    }
} 


