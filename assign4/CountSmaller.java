import java.util.*;

public class CountSmaller {

    static class Pair {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    static int[] ans;

    static void mergeSort(Pair[] arr, int low, int high) {

        if (low >= high)
            return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

    static void merge(Pair[] arr, int low, int mid, int high) {

        Pair[] temp = new Pair[high - low + 1];

        int left = low;
        int right = mid + 1;
        int k = 0;

        int rightCount = 0;

        while (left <= mid && right <= high) {

            if (arr[left].value <= arr[right].value) {

                ans[arr[left].index] += rightCount;
                temp[k++] = arr[left++];

            } else {

                rightCount++;
                temp[k++] = arr[right++];
            }
        }

        while (left <= mid) {
            ans[arr[left].index] += rightCount;
            temp[k++] = arr[left++];
        }

        while (right <= high) {
            temp[k++] = arr[right++];
        }

        for (int i = 0; i < temp.length; i++) {
            arr[low + i] = temp[i];
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Pair[] arr = new Pair[n];
        ans = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(sc.nextInt(), i);
        }

        mergeSort(arr, 0, n - 1);

        for (int x : ans)
            System.out.print(x + " ");

        sc.close();
    }
}
