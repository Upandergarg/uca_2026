// import java.util.PriorityQueue;

// class ClinicsVillage {
    
//     public static int minimumMaximumLoad(int[] population, int k) {

//         PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
//             int loadA = (a[0] + a[1] - 1) / a[1];
//             int loadB = (b[0] + b[1] - 1) / b[1];
//             return loadB - loadA;   // Max Heap
//         });

//         // Initially every village gets 1 clinic
//         for (int p : population) {
//             pq.offer(new int[]{p, 1});
//         }

//         int extra = k - population.length;

//         while (extra-- > 0) {

//             int[] village = pq.poll();

//             village[1]++;   // Increase clinics

//             pq.offer(village);
//         }

//         int[] ans = pq.peek();
//         return (ans[0] + ans[1] - 1) / ans[1];
//     }


//     public static void main(String[] args) {

//         int[] population = {200, 20, 50};
//         int k = 5;

//         System.out.println(minimumMaximumLoad(population, k));
//     }
// }

public class ClinicsVillage {

    // Check if maxLoad is possible
    static boolean canAllocate(int[] population, int k, int maxLoad) {

        int clinicsNeeded = 0;

        for (int people : population) {

            // ceil(people / maxLoad)
            clinicsNeeded += (people + maxLoad - 1) / maxLoad;

            if (clinicsNeeded > k)
                return false;
        }

        return true;
    }

     static int minimumMaximumLoad(int[] population, int k) {

        int low = 1;
        int high = 0;

        // Find maximum population
        for (int people : population)
            high = Math.max(high, people);

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canAllocate(population, k, mid)) {
                ans = mid;
                high = mid - 1;      // Try smaller answer
            } else {
                low = mid + 1;       // Need larger answer
            }
        }

        return ans;
    }

    public static void main(String[] args) {

        int[] population = {200, 20, 50};
        int k = 5;

        System.out.println(minimumMaximumLoad(population, k));
    }
}