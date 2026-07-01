import java.util.Random;

public class bubblesortJava {

 
    public static void bubbleSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {

                if (arr[j] > arr[j + 1]) {

                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                }
            }
        }
    }

    
    public static void generateNumbers(int[] arr) {
        Random random = new Random();

        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(100000);
        }
    }

    public static void main(String[] args) {

        int size1 = 40000;
        int size2 = 80000;

        int[] arr1 = new int[size1];
        int[] arr2 = new int[size2];

        generateNumbers(arr1);

        long start = System.nanoTime();
        bubbleSort(arr1);
        long end = System.nanoTime();

        double time1 = (end - start) / 1_000_000_000.0;

        generateNumbers(arr2);

        long start2 = System.nanoTime();
        bubbleSort(arr2);
        long end2 = System.nanoTime();

        double time2 = (end2 - start2) / 1_000_000_000.0;
        System.out.println(time2 / time1);
    }
}
