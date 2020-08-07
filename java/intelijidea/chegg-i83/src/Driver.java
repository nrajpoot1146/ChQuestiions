import java.io.File;

public class Driver {
    public static void main(String... args){
        NameListSorted nList = new NameListSorted(); // initialize a list

        nList.add(new Name("B", "B"));
        nList.add(new Name("A", "A"));
        nList.add(new Name("D", "D"));
        System.out.println(nList.size());
        nList.print();
        System.out.println(nList.search(new Name("B", "B")));
        nList.remove(new Name("B", "B"));
        System.out.println(nList.size());
        nList.add(new Name("D", "D"));
        nList.add(new Name("A", "A"));
        nList.add(new Name("D", "D"));
        nList.print();
        System.out.println(nList.size());
        System.out.println(nList.search(new Name("B", "B")));
        nList.remove(new Name("D", "D"));
        nList.print();
        System.out.println(nList.search(new Name("D", "D")));
        nList.remove(new Name("A", "A"));
        nList.print();
        System.out.println(nList.size());
        nList.add(new Name("D", "D"));
        nList.add(new Name("A", "A"));
        nList.add(new Name("D", "D"));
        nList.add(new Name("B", "B"));
        nList.print();
        System.out.println();
        nList.sublist(1, 4).print();


//        nList.build(new File("name.txt")); // build a list from file
//        System.out.println("initial list: ");
//        nList.print();
//        System.out.println();
//
//        nList.remove(new Name("Mike", "Jones"));
//        System.out.println("list after removing Mike Jones");
//        nList.print();
//        System.out.println();
//
//        NameListSorted newList = nList.sublist(4, 7);
//        System.out.println("new sublist from index 4, 7");
//        newList.print();
    }
}
