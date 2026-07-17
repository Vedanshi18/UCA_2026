import java.util.*;
class remove_duplicates {
    private HashMap<String, Integer> map;
    private Queue<String> queue;
    public remove_duplicates() {
        map = new HashMap<>();
        queue = new LinkedList<>();
    }
    public boolean shouldPrintMessage(int timestamp, String msg) {
        // First time message
        if (!map.containsKey(msg)) {
            map.put(msg, timestamp);
            queue.offer(msg);
            return true;
        }
        int lastTime = map.get(msg);
        // More than or equal to 10 seconds
        if (timestamp - lastTime >= 10) {
            map.put(msg, timestamp);
            return true;
        }
        // Duplicate within 10 sec
        return false;
    }
    public boolean shouldPrintMessage2(int timestamp, String msg) {
        // First time message
        if (!map.containsKey(msg)) {
            map.put(msg, timestamp);
            queue.offer(msg); // Add the message to the queue
        }
        int lastTime = map.get(msg);
        // More than or equal to 10 seconds
        if (timestamp - lastTime >= 10) {
            queue.offer(msg); // Add the message to the queue
            map.put(msg, timestamp); // Update the timestamp in map
        }
        else{
            queue.offer(queue.poll());
        }
        if(map.get(queue.peek()) - lastTime > 10){
            return true;
        }
        // Duplicate within 10 sec
        return false;
    }
    public static void main(String args[]) {
        remove_duplicates logger = new remove_duplicates();
        System.out.println(logger.shouldPrintMessage(1, "foo"));  
        System.out.println(logger.shouldPrintMessage(2, "bar"));  
        System.out.println(logger.shouldPrintMessage(3, "foo"));  
        System.out.println(logger.shouldPrintMessage(11, "foo"));  

        System.out.println(logger.shouldPrintMessage2(1, "foo"));  
        System.out.println(logger.shouldPrintMessage2(2, "bar"));  
        System.out.println(logger.shouldPrintMessage2(3, "foo"));  
        System.out.println(logger.shouldPrintMessage2(11, "foo"));  

    }
}
