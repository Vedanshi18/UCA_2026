import java.util.*;
public class clinicAndVillage {
    static class Village {
        int population;
        int clinics;

        Village(int population, int clinics) {
            this.population = population;
            this.clinics = clinics;
        }

        double load() {
        return (double) population / clinics;
        }
    }
    public static double minMaxLoad(int[] population, int k) {
        PriorityQueue<Village> pq = new PriorityQueue<>((a,b) -> Double.compare(b.load(), a.load()));
        int n = population.length;

        // Every village -> one clinic atleast
        for (int i = 0; i < n; i++) {
            pq.offer(new Village(population[i], 1));
        }

        int remaining = k - n;

        while (remaining > 0) {
            Village v = pq.poll(); // Village with highest current load
            v.clinics++; // Give it one more clinic
            pq.offer(v); // Put it back
            remaining--;
        }
        return pq.peek().load(); // Return village with highest load after distribution
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of villages: ");
        int n = scanner.nextInt();
        int[] population = new int[n];
        System.out.print("Enter the population of each village: ");
        for (int i = 0; i < n; i++) {
            population[i] = scanner.nextInt();
        }
        System.out.print("Enter the number of clinics: ");
        int k = scanner.nextInt();
        double answer = minMaxLoad(population, k);
        System.out.printf("%.2f%n", answer);
        scanner.close();
    }
}