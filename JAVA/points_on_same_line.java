import java.util.HashMap;
import java.util.Map;

public class points_on_same_line {
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public int maxPoints(int[][] points) {
        if (points.length <= 2) return points.length;
        int max = 1;
        for (int i = 0; i < points.length; i++) {
            Map <String, Integer> slopeCounts  = new HashMap<>();
            int duplicates = 0;
            int localMax = 0;
            for (int j = i + 1; j < points.length; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1]; 
                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                // Ensure consistency
                // slope(1,-1) == slope(-1,1)
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                
                String slopeKey = dy + "/" + dx;

                int curr = slopeCounts.merge(
                    slopeKey, 1, Integer::sum
                );

                localMax = Math.max(localMax, curr);
            }
        }
        return max;
    }
    public static void main(String[] args) {

        System.out.println(maxPoints(points));
        // Test 1: Horizontal line
        int[][] points1 = {
            {1, 5},
            {2, 5},
            {3, 5},
            {4, 5}
        };

        System.out.println("Test 1: " + maxPoints(points1));

        // Test 2: Vertical line
        int[][] points2 = {
            {3, 1},
            {3, 2},
            {3, 5},
            {3, 10}
        };
        System.out.println("Test 2: " + maxPoints(points2));


        // Test 3: Diagonal line
        int[][] points3 = {
            {1, 1},
            {2, 2},
            {3, 3},
            {4, 4}
        };

        System.out.println("Test 3: " + maxPoints(points3));
    }
}
