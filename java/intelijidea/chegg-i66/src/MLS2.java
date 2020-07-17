import java.util.Random;

public class MLS2 {
    public static void main(String... args) throws StackException {
        Stack<Integer> stack = new Stack<>(15);

        // push 10 random elements into stack
        Random random = new Random();
        for (int i = 0; i < 10; i++){
            int num = random.nextInt(100);
            System.out.println("Push : "+num);
            stack.push(num);
        }

        System.out.println("Top of the stack: "+stack.pop());
        System.out.println("isEmpty: "+stack.isEmpty());
        // pop 3 elements from stack
        stack.pop();
        stack.pop();
        stack.pop();
        System.out.println("Top of the stack: "+stack.pop());
        // pop all elements
        while (!stack.isEmpty()){
            stack.pop();
        }
        System.out.println("isEmpty (after popping all elements) : "+stack.isEmpty());

    }
}
