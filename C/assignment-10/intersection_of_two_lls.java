import java.util.*;
public class intersection_of_two_lls {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    static Node intersection(Node head1, Node head2) {
        Node dummy = new Node(-1);
        Node curr = dummy;
        Node p1 = head1, p2 = head2;
        while(p1 != null && p2 != null) {
            if (p1.data == p2.data) {
                curr.next = new Node(p1.data);
                curr = curr.next;
                p1 = p1.next;
                p2 = p2.next;
            }
            else if (p1.data < p2.data) {
                p1 = p1.next;
            }
            else {
                p2 = p2.next;
            }
        }
        return dummy.next;
    }
    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data);

            if (head.next != null)
                System.out.print(" -> ");

            head = head.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {

        // 1 -> 2 -> 2 -> 3 -> 4
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(2);
        head1.next.next.next = new Node(3);
        head1.next.next.next.next = new Node(4);

        // 2 -> 2 -> 2 -> 4
        Node head2 = new Node(2);
        head2.next = new Node(2);
        head2.next.next = new Node(2);
        head2.next.next.next = new Node(4);

        Node result = intersection(head1, head2);

        printList(result);
    }

}
