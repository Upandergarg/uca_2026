import java.util.PriorityQueue;

public class DataStream {

    static class RunningMedian {

        PriorityQueue<Integer> maxHeap;
        PriorityQueue<Integer> minHeap;

        public RunningMedian() {
            maxHeap = new PriorityQueue<>((a, b) -> b - a); // Max Heap
            minHeap = new PriorityQueue<>();                // Min Heap
        }

        void insert(int num) {

            if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
                maxHeap.offer(num);
            } else {
                minHeap.offer(num);
            }

            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.offer(maxHeap.poll());
            } else if (minHeap.size() > maxHeap.size() + 1) {
                maxHeap.offer(minHeap.poll());
            }
        }

        double getMedian() {

            if (maxHeap.size() == minHeap.size()) {
                return (maxHeap.peek() + minHeap.peek()) / 2.0;
            } else if (maxHeap.size() > minHeap.size()) {
                return maxHeap.peek();
            } else {
                return minHeap.peek();
            }
        }
    }

    public static void main(String[] args) {

        RunningMedian rm = new RunningMedian();

        rm.insert(5);
        System.out.println(rm.getMedian());

        rm.insert(15);
        System.out.println(rm.getMedian());

        rm.insert(1);
        System.out.println(rm.getMedian());

        rm.insert(3);
        System.out.println(rm.getMedian());
    }
}