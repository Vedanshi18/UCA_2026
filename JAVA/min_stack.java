import java.util.*;
class min_stack {
    Stack <Integer> st;
    Stack <Integer> minSt;
    public min_stack() {
        st = new Stack<>();
        minSt = new Stack<>();
    }

    public void push(int val) {
        st.push(val);
        if(minSt.isEmpty())
            minSt.push(val);
        else minSt.push(Math.min(val, minSt.peek()));
    }

    public int pop() {
        if (st.isEmpty()) {
            System.out.println("Empty");
            return -1;
        }
        minSt.pop();
        return st.pop();
    }

    public int top() {
        if (st.isEmpty()) {
            System.out.println("Empty");
            return -1;
        }
        return st.peek();
    }

    public int getMin() {
        if (minSt.isEmpty()) {
            System.out.println("Empty");
            return -1;
        }
        return minSt.peek();
    }
    
    public static void main(String args[]) {
        min_stack st = new min_stack();

        st.push(-2);
        st.push(0);
        st.push(-3);

        System.out.println(st.getMin());

        st.pop();

        System.out.println(st.top());

        System.out.println(st.getMin());
    }
}