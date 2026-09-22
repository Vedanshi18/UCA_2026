import java.time.LocalDate;
import java.util.*;

public class Employee {
    private int employeeId;
    private String name;
    private String department;
    private double salary;
    private int age;
    private LocalDate joiningDate;
    private double rating;

    public Employee(int employeeId, String name, String department,
            double salary, int age, LocalDate joiningDate, double rating) {
        this.employeeId = employeeId;
        this.name = name;
        this.department = department;
        this.salary = salary;
        this.age = age;
        this.joiningDate = joiningDate;
        this.rating = rating;
    }

    public int getEmployeeId() {
        return employeeId;
    }

    public String getName() {
        return name;
    }

    public String getDepartment() {
        return department;
    }

    public double getSalary() {
        return salary;
    }

    public int getAge() {
        return age;
    }

    public LocalDate getJoiningDate() {
        return joiningDate;
    }

    public double getRating() {
        return rating;
    }

    @Override
    public String toString() {
        return name + " | " + department + " | ₹" + salary +
                " | age " + age + " | joined " + joiningDate;
    }

    public static void main(String[] args) {

        List<Employee> employees = new ArrayList<>(List.of(
                new Employee(1, "Aarav", "Engineering", 120000, 29, LocalDate.of(2021, 3, 15), 4.5),
                new Employee(2, "Anika", "Sales", 95000, 34, LocalDate.of(2019, 7, 1), 3.8),
                new Employee(3, "Bhavya", "Engineering", 135000, 41, LocalDate.of(2015, 1, 10), 4.9),
                new Employee(4, "Chirag", "Marketing", 88000, 25, LocalDate.of(2022, 11, 5), 4.1),
                new Employee(5, "Aditi", "Sales", 110000, 30, LocalDate.of(2020, 6, 20), 4.6),
                new Employee(6, "Aman", "Engineering", 102000, 27, LocalDate.of(2021, 9, 12), 3.9),
                new Employee(7, "Divya", "Marketing", 75000, 23, LocalDate.of(2023, 2, 1), 4.0),
                new Employee(8, "Aryan", "Sales", 140000, 38, LocalDate.of(2016, 4, 18), 4.7)));

        // 1. Sort by name (natural alphabetical order using a Comparator, not
        // Comparable)
        Collections.sort(employees, (e1, e2) -> {
            return e1.getName().compareTo(e2.getName());
        });
        System.out.println(employees);

        // 2. Sort by salary, descending
        Collections.sort(employees, (e1, e2) -> {
            return Double.compare(e2.getSalary(), e1.getSalary());
        });
        System.out.println(employees);

        // 3. Give preference: name starts with "A" on top AND salary > 100000, sorted
        // by salary descending
        Collections.sort(employees, (e1, e2) -> {
            boolean p1 = e1.getName().startsWith("A") && e1.getSalary() > 100000;
            boolean p2 = e2.getName().startsWith("A") && e2.getSalary() > 100000;

            if (p1 & !p2)
                return -1;
            if (!p1 & p2)
                return 1;
            return Double.compare(e2.getSalary(), e1.getSalary());
        });
        System.out.println(employees);

        // 4. Sort by department, then by name within each department
        Collections.sort(employees, (e1, e2) -> {
            int result = e1.getDepartment().compareTo(e2.getDepartment());

            if (result != 0)
                return result;
            return e1.getName().compareTo(e2.getName());
        });
        System.out.println(employees);

        // 5. Sort by age, ascending
        Collections.sort(employees, (e1, e2) -> {
            return Integer.compare(e1.getAge(), e2.getAge());
        });
        System.out.println(employees);

        // 6. Sort by joining date, oldest employee (earliest date) first
        Collections.sort(employees, (e1, e2) -> {
            return e1.getJoiningDate().compareTo(e2.getJoiningDate());
        });

        // 7. Sort by rating descending, then by salary descending as a tiebreaker
        Collections.sort(employees, (e1, e2) -> {
            int result = Double.compare(e2.getRating(), e1.getRating());
            if (result != 0) {
                return result;
            }
            return Double.compare(e2.getSalary(), e1.getSalary());
        });
    }
}