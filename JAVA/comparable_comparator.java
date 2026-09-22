// import java.util.*;
// class comparable_comparator {
//     // public boolean isPrime(int number) {
//     //     if (number <= 1) {
//     //         return false;
//     //     }
//     //     for (int i = 2; i <= Math.sqrt(number); i++) {
//     //         if (number % i == 0) {
//     //             return false;
//     //         }
//     //     }
//     //     return true;
//     // }
//     static boolean isPrime(int x) {
//         if (x <= 1) return false;
//         if (x == 2) return true;    
//         for (int i = 2; i * i <= x; i++) {
//             if (x % i == 0)
//                 return false;
//         }

//         return true;
//     }
//     public static void main(String args[]) {
//         List <Integer> numbers = new ArrayList<>();
//         numbers.add(2);
//         numbers.add(3);
//         numbers.add(100);
//         numbers.add(900);
//         numbers.add(600);
//         numbers.add(23);

//         Collections.sort(numbers, (e1, e2) -> {
//             if (isPrime(e1) && !isPrime(e2))
//                 return -1;
//             else if (!isPrime(e1) && isPrime(e2))
//                 return 1;
//             else if (!isPrime(e1) && !isPrime(e2))
//                 return Integer.compare(e2, e1);  // Larger first
//             return Integer.compare(e1, e2); // Smaller first
//         });
//         System.out.println(numbers);
//     }   
// }

import java.util.*;
import java.lang.*;
import java.io.*;

class comparable_comparator
{
    static class UCAStudent implements Comparable<UCAStudent> {
        String studentName;
        double CGPA;
        
        UCAStudent(String studentName, double CGPA) {
            this.studentName = studentName;
            this.CGPA = CGPA;
        }
        
        public int compareTo(UCAStudent e2) {
            UCAStudent e1 = this;
            
           // e1 on top then return negative value
           // e2 on top then return postive value
           // if equal return zero value
           return Double.compare(e2.CGPA , e1.CGPA);

           //cg less on top, if same cg, then alphabetIcally descending order
        }
        
        public String toString() {
            return studentName + " " + CGPA;
        }
    }
    
    public static void main (String[] args) throws java.lang.Exception
    {
        List<UCAStudent> list  = new ArrayList<>();
        list.add(new UCAStudent("A", 6.0d));
        list.add(new UCAStudent("B", 7.0d));
        list.add(new UCAStudent("C", 8.0d));
        
        Collections.sort(list);
        
        System.out.println(list);
    }
}
/*
import java.util.ArrayList;
import java.util.Collections;

class UCA implements Comparable<UCA> {
    String studentName;
    double cgpa;

    UCA(String studentName, double cgpa) {
        this.studentName = studentName;
        this.cgpa = cgpa;
    }

    public String toString() {
        return this.studentName + " " + this.cgpa;
    }

    public int compareTo(UCA s2) {
        if (this.cgpa == s2.cgpa) {
            return this.studentName.compareTo(s2.studentName);
        }

        return Double.compare(this.cgpa, s2.cgpa);
    }

    public static void main(String[] args) {
        ArrayList<UCA> list = new ArrayList<>();

        list.add(new UCA("STUDENT1", 8.89));
        list.add(new UCA("STUDENT2", 9.89));
        list.add(new UCA("STUDENT3", 7.89));
        list.add(new UCA("STUDENT", 7.0));
        list.add(new UCA("STUBENT", 7.0));

        Collections.sort(list);

        System.out.println(list);
    }
}
     */