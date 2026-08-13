import java.util.*;
public class running_median {
    // Max heap
    PriorityQueue<Integer> left =
        new PriorityQueue<>(Collections.reverseOrder());
    // Min heap
    PriorityQueue<Integer> right =
        new PriorityQueue<>();

    public void insert(int num) {
        //Insert number in the right heap
        if (left.isEmpty() || num <= left.peek()) {
            left.offer(num);
        } else {
            right.offer(num);
        }

        // Balance both heaps
        if (left.size() > right.size() + 1) {
            right.offer(left.poll());
        } 
        else if (right.size() > left.size()) {
            left.offer(right.poll());
        }
    }
    public float getMedian() {
        if (left.size() > right.size()) {
            return left.peek();
        }
        return (left.peek() + right.peek()) / 2.0f;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements to insert: ");
        int n = scanner.nextInt();
        running_median rm = new running_median();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            int num = scanner.nextInt();
            rm.insert(num);
            System.out.println(rm.getMedian());
        }
        scanner.close();
    }
}