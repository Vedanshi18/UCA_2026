import java.util.*;

class SnakeGame {

    int width;
    int height;

    // Food positions
    int[][] food;
    int foodIndex;

    // Snake body
    // head -> front, tail -> back
    Deque<int[]> snake;

    // To quickly check whether a cell is occupied by snake
    Set<String> occupied;

    int score;

    public SnakeGame(int width, int height, int[][] food) {
        this.width = width;
        this.height = height;
        this.food = food;

        foodIndex = 0;
        score = 0;

        snake = new LinkedList<>();
        occupied = new HashSet<>();

        // Snake starts at (0,0)
        int[] start = {0, 0};
        snake.addFirst(start);
        occupied.add("0,0");
    }

    public int move(String direction) {

        // 1. Get current head
        int[] head = snake.peekFirst();

        int newRow = head[0];
        int newCol = head[1];

        // 2. Calculate new head position
        if (direction.equals("U")) {
            newRow--;
        }
        else if (direction.equals("D")) {
            newRow++;
        }
        else if (direction.equals("L")) {
            newCol--;
        }
        else if (direction.equals("R")) {
            newCol++;
        }

        // 3. Check boundary
        // if outside grid -> return -1
        if (newCol >= width) return -1;
        if (newRow >= height) return -1;

        // 4. Check if food is eaten
        boolean ateFood = false;

        // if foodIndex < food.length
        // and new position == food[foodIndex]
        // then ateFood = true
        // score++
        // foodIndex++


        // 5. If NOT eating food,
        // remove tail BEFORE checking collision
        // because moving into the old tail position is allowed


        // 6. Check whether new head collides with body
        // if occupied contains new position -> return -1


        // 7. Add new head
        // snake.addFirst(...)
        // occupied.add(...)


        // 8. Return score
        return score;
    }
}