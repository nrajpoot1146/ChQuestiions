public class LibraryTest {

    public static void main(String[] args) {

        Library library = new Library ();

        Librarian librarian = new Librarian (library);

        Thread thread = new Thread (librarian);

        thread.start ();

        ReadingHorse customer1 = new ReadingHorse("Ola Nordmann", "Ibsen", library);

        thread = new Thread (customer1);

        thread.start ();

        ReadingHorse customer2 = new ReadingHorse ("Kari Nordmann", "Bjornson", library);

        thread = new Thread (customer2);

        thread.start ();

    }

}