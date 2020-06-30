import java.util.LinkedList;

public class BookStore {
    public static void main(String[] args){
        LinkedList<Book> linkedList = new LinkedList<Book>();

        Book[] books = new Book[4];
        books[0] = new Book("Harry Potter Philosopher's Stone", "J. K. Rowling", "1997");
        books[1] = new Book("Harry Potter Chamber of Secrets", "J. K. Rowling", "1998");
        books[2] = new Book("Harry Potter Prisoner of Azkaban", "J. K. Rowling", "1999");
        books[3] = new Book("Harry Potter Goblet of Fire", "J. K. Rowling", "2000");

        // adding 4 books to linked list
        for (int i=0; i<books.length; i++){
            linkedList.add(books[i]);
        }

        System.out.println("After adding four books to linked list: ");
        printLinkedList(linkedList);
        System.out.println();

        // push 2 new books to linked list
        linkedList.push(new Book("Harry Potter Order of the Phoenix", "J. K. Rowling", "2003"));
        linkedList.push(new Book("Harry Potter Half-Blood Prince", "J. K. Rowling", "2005"));

        System.out.println("After adding two new books to linked list: ");
        printLinkedList(linkedList);
        System.out.println();

        // print last element without removing
        System.out.println(linkedList.peekLast().toString());

        // print first element without removing
        // peekfirst function return the last pushed element
        System.out.println(linkedList.peekFirst().toString());
        System.out.println();

        // pop last three Books
        linkedList.pop();
        linkedList.pop();
        linkedList.pop();

        // print list
        System.out.println("After pop of last three books: ");
        printLinkedList(linkedList);

        linkedList.clear();

    }

    public static void printLinkedList(LinkedList<Book> linkedList){
        for (Book b : linkedList){
            System.out.println(b.toString());
        }
    }
}
