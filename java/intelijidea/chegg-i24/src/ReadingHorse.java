import java.util.ArrayList;

public class ReadingHorse implements Runnable{
    private Library library;
    private String author;
    private String title;

    ReadingHorse(String author, String title, Library library){
        this.author = author;
        this.title = title;
        this.library = library;
    }

    @Override
    public void run() {

        for (int i = 0; ; i++){
            ArrayList<Book> arrayList = library.getArrayList();
            if(i < library.getCount()) {

                Book book = arrayList.get(i);

                if (book.getAuthor().equalsIgnoreCase(this.author) && book.getTitle().equalsIgnoreCase(this.title)) {
                    System.out.println("Author: " + this.author + " Title: " + this.title);
                }
            }else{
                i = 0;
            }


            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
