import java.util.Random;

public class QuickSelect {

    static Random random = new Random();

    // Generate random numbers
    static void generateArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(100000);
        }
    }

    // Partition
    static int partition(int[] arr, int low, int high) {

        int pivot = arr[high];
        int i = low;

        for (int j = low; j < high; j++) {

            if (arr[j] <= pivot) {

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                i++;
            }
        }

        int temp = arr[i];
        arr[i] = arr[high];
        arr[high] = temp;

        return i;
    }

    // Quick Select
    static void quickSelect(int[] arr, int low, int high, int k) {

        if (low >= high)
            return;

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return;

        if (pivotIndex > k)
            quickSelect(arr, low, pivotIndex - 1, k);
        else
            quickSelect(arr, pivotIndex + 1, high, k);
    }

    // Measure Time
    static double measureTime(int[] arr, int k) {

        long start = System.nanoTime();

        quickSelect(arr, 0, arr.length - 1, k - 1);

        long end = System.nanoTime();

        return (end - start) / 1000000.0;
    }

    public static void main(String[] args) {

        int[] sizes = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};

        int k = 100;

        System.out.println("Dataset Size\tTime (ms)");

        for (int n : sizes) {

            int[] arr = new int[n];

            generateArray(arr);

            double time = measureTime(arr, k);

            System.out.printf("%d\t\t%.3f\n", n, time);
        }

        // Demo
        System.out.println("\nExample:");

        int[] arr = new int[20];
        generateArray(arr);

        System.out.println("Original Array:");

        for (int x : arr)
            System.out.print(x + " ");

        System.out.println();

        quickSelect(arr, 0, arr.length - 1, 4);

        System.out.println("\nSmallest 5 Elements:");

        for (int i = 0; i < 5; i++)
            System.out.print(arr[i] + " ");
    }
}
