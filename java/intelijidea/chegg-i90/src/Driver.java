public class Driver {
    public static void main(String... argv){
        Stack<Integer> stack = new Stack<>(4);

        stack.push(8);
        stack.push(45);
        stack.push(32);
        stack.push(70);
        // now stack is full
        stack.print();
        System.out.println("isFull: "+stack.isOverflowed());
        // this will add into linked list
        stack.push(40);
        stack.print();

        System.out.println("Top of the stack: "+stack.top());
        // pop an element from the stack
        stack.pop();
        System.out.println("After Top of the stack: "+stack.top());
        stack.print();
    }
}
