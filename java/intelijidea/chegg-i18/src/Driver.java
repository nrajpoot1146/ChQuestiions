import java.util.List;

public class Driver {
    public static Library library = new Library();
    public static void main(String[] args){

        library.addItem(new Item("Physics"));
        library.addItem(new Item("Physics"));
        library.addItem(new Item("Physics"));
        library.addItem(new Item("Physics"));
        library.addItem(new Item("Chem"));
        library.addItem(new Item("Chem"));

        System.out.println("Before:");
        printList();
        System.out.println();
        System.out.println();
        library.checkOut("Physics",1,"Rm");

        System.out.println("After:");
        printList();
    }

    public static void printList(){
        List<Item> list = library.getItems();
        for(Item i : list){
            System.out.println(i.getCallNumber()+" "+i.getCopyNo());
        }
    }
}
