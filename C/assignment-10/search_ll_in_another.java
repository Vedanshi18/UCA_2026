import java.util.*;
class search_ll_in_another {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static String searchList(Node list1, Node list2) {
        // Empty list1 is considered present
        if (list1 == null) return "Yes";
        
        Node p1 = list1, p2 = list2;
        
        while (p2 != null) {
            Node start = p2;   // remember where this comparison started
            while (p1 != null && p2 != null && p1.data == p2.data) {
                p1 = p1.next;
                p2 = p2.next;
            }
            // If we reached the end of list1, it means we found a match
            if (p1 == null) return "Yes";
            p1 = list1;
            p2 = start.next; // Move to the next node in list2
        }
        return "No";
    }

    public static void main(String[] args) {

        // list1 = 1 -> 2
        Node list1 = new Node(1);
        list1.next = new Node(2);

        // list2 = 5 -> 1 -> 2 -> 3
        Node list2 = new Node(5);
        list2.next = new Node(1);
        list2.next.next = new Node(2);
        list2.next.next.next = new Node(3);

        System.out.println(searchList(list1, list2));
    }
}