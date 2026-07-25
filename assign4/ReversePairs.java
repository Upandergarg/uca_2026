import java.util.*;

public class ReversePairs {

    static int mergeSort(int[] nums, int low, int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);

        count += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);

        return count;
    }

    static int countPairs(int[] nums, int low, int mid, int high) {

        int count = 0;
        int right = mid + 1;

        for (int left = low; left <= mid; left++) {

            while (right <= high && (long) nums[left] > 2L * nums[right]) {
                right++;
            }

            count += right - (mid + 1);
        }

        return count;
    }

    static void merge(int[] nums, int low, int mid, int high) {

        ArrayList<Integer> temp = new ArrayList<>();

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                temp.add(nums[left++]);
            } else {
                temp.add(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.add(nums[left++]);
        }

        while (right <= high) {
            temp.add(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp.get(i - low);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] nums = new int[n];

        System.out.println("Enter array elements:");

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int ans = mergeSort(nums, 0, n - 1);

        System.out.println("Significant Reverse Pairs = " + ans);

        sc.close();
    }
}
