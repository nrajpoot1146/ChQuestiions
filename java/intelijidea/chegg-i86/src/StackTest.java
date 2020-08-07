public class StackTest {
    public static void main(String...  args){
        Stack s1 = new Stack(10); // declare stack of capacity 10
        Stack s2 = new Stack(10);

        // user 1
        user u1 = new user();
        Name n1 = new Name("john","R");
        u1.setAge(11);
        u1.setname(n1);

        // user 2
        user u2 = new user();
        Name n2 = new Name("Mike","S");
        u2.setAge(10);
        u2.setname(n2);

        // user 3
        user u3 = new user();
        Name n3 = new Name("Sonam","Singh");
        u3.setAge(45);
        u3.setname(n3);

        // user 4
        user u4 = new user();
        Name n4 = new Name("Raja","Rana");
        u4.setAge(9);
        u4.setname(n4);

        // push all 4 user into stack 1
        s1.push(u1);
        s1.push(u2);
        s1.push(u3);
        s1.push(u4);

        // print stack 1
        System.out.println("stack 1: ");
        s1.print();

        // push all four user into stack 2
        s2.push(u1);
        s2.push(u2);
        s2.push(u3);
        s2.push(u4);

        // print stack 2
        System.out.println("\nstack 2:");
        s2.print();

        // equality test 1
        System.out.print("Equality test 1: ");
        if (s1.isEqual(s2)){
            System.out.println("passed");
        }else {
            System.out.println("failed");
        }

        System.out.println("\nPop an element from stack 2");
        System.out.println(s2.pop().toString());


        System.out.println("\nstack 2:");
        s2.print();

        // equality test 2
        System.out.print("Equality test 2: ");
        if (!s1.isEqual(s2)){
            System.out.println("passed");
        }else {
            System.out.println("failed");
        }
    }
}
