public class Librarian implements Runnable{
    private Library library;

    Librarian(Library library){
        this.library = library;
    }

    @Override
    public void run() {
        for (int i = 0; i<100; i++){
            while (library.isFull());

            if(i == 19){
                library.deliverBook(new Book("Kari Nordmann", "Bjornson"));
            }else if(i == 27){
                library.deliverBook(new Book("Ola Nordmann", "Ibsen"));
            }else{
                library.deliverBook(new Book("author"+i, "title"+i));
            }
        }
    }
}
