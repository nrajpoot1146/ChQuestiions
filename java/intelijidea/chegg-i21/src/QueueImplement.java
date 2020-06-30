import java.util.Scanner;

public class QueueImplement {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Size of integer Queue ");
        int size = sc.nextInt();
        sc.nextLine();

        ArrayQueue arrayQueue = new ArrayQueue(size);

        while (true){
            menu();
            char op = sc.nextLine().charAt(0);

            switch (op){
                case '1':
                    System.out.println("Enter an integer: ");
                    arrayQueue.enqueue(sc.nextInt());
                    sc.nextLine();
                    break;
                case '2':
                    arrayQueue.deQueue();
                    break;
                case '3':
                    System.out.println("peek = "+arrayQueue.peek());
                    break;
                case '4':
                    System.out.println("Empty status = "+arrayQueue.isEmpty());
                    if(arrayQueue.isEmpty())
                        System.out.println("Queue = Empty");
                    else{
                        System.out.println("Queue = "+arrayQueue.toString());
                    }
                    break;
                case '5':
                    System.out.println("Full status = "+arrayQueue.isFull());
                    break;
                case '6':
                    System.out.println("size = "+arrayQueue.getSize());
                    break;
                default:
                    break;
            }

            System.out.println("Do you want to continue (Type y or n)");
            char ch = sc.nextLine().charAt(0);
            while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N'){
                ch = sc.nextLine().charAt(0);
            }
            if(ch == 'n' || ch == 'N'){
                break;
            }
        }

    }

    public static void menu(){
        System.out.println("Queue Operations");
        System.out.println("1. insert");
        System.out.println("2. remove");
        System.out.println("3. peek");
        System.out.println("4. check empty");
        System.out.println("5. check full");
        System.out.println("6. size");
    }
}
