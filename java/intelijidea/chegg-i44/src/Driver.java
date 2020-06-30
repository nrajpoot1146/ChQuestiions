import java.util.*;

public class Driver {
    private static final ArrayStack stack = new ArrayStack();
    private static final ArrayQueue queue = new ArrayQueue();
    
    public static void main(String[] args){

        int n = 4;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter value of n: ");
        n = scanner.nextInt();

        // generate random number and push into stack
        Random random = new Random();
        for (int i = 0; i<n; i++){
            Integer newV = random.nextInt(n) % n;
            Element e = new Element(newV, newV.toString());
            stack.push(e);
            System.out.print("ph("+newV+") ");
        }

        System.out.println();
        // sorting steps
        for (int i = 1; i <= n-1; i++){
            if (i == n-1){
                System.out.println("Program written by Your Name/012345678. One more step needed to finish!");
            }
            int minPos = 0;
            Element minVal = new Element(n, Integer.toString(n));
            System.out.println("Step: "+i);

            System.out.println("Step "+i+".A");
            // step i.A
            // find minimum value and its position
            // pop data from stack and enqueue into queue
            for (int j = stack.size(); j >= i; j--) {
                Element top = stack.pop();
                System.out.print("pp ");
                if (minVal.getKeyValue() > top.getKeyValue()) {
                    minVal = top;
                    minPos = j;
                }
                queue.enQueue(top);
                System.out.print("eq("+top.getKeyValue()+") ");
            }
            System.out.println("Min. pos. is: "+minPos+"; Min key value is: "+minVal.getKeyValue());

            System.out.println("Step "+i+".B");
            // step i.B
            // remove minimum value from queue
            // store in another variable
            while (!queue.queueEmpty()){
                Element front = queue.deQueue(); // deque from queue
                System.out.print("dQ ");
                if (minVal.getKeyValue() == front.getKeyValue()){
                    break;
                }
                stack.push(front); // push into stack
                System.out.print("ph("+front.getKeyValue()+") ");
            }

            System.out.println();
            System.out.println("Step "+i+".C");
            // step i.C
            for (int j = stack.size(); j >= i; j--){
                Element top = stack.pop(); // pop from stack
                System.out.print("pp ");
                queue.enQueue(top); // enqueue into stack
                System.out.print("eQ("+top+") ");
            }

            System.out.println();
            System.out.println("Step "+i+".D");
            // step i.D
            // push minimum value into stack
            stack.push(minVal); // push into stack
            System.out.println("ph("+minVal.getKeyValue()+")");

            System.out.println("Step "+i+".E");
            // step i.E
            while (!queue.queueEmpty()){
                Element front = queue.deQueue(); // dequeue from queue
                System.out.print("dQ ");
                stack.push(front); // push into stack
                System.out.print("ph("+front.getKeyValue()+") ");
            }
            System.out.println();
            System.out.println();
        }
        System.out.println("Final sorted stack : ");
        System.out.println(stack.toString());
    }
}
