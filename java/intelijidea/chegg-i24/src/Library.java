import java.util.ArrayList;

public class Library {
    private ArrayList<Book> arrayList;
    private final static int MAX_SIZE = 50;
    private int count;

    Library(){
        this.arrayList = new ArrayList<Book>();
        this.count = 0;
    }

    public void deliverBook(Book book){
        if(isFull()){
            return;
        }
        this.count++;
        arrayList.add(book);
    }

    public Book getBook(String author){
        if (isEmpty()){
            return null;
        }
        for ( Book b : arrayList){
            if(b.getAuthor().equalsIgnoreCase(author)){
                return b;
            }
        }
        return null;
    }

    public ArrayList<Book> getArrayList() {
        return arrayList;
    }

    public boolean isFull(){
        return this.count == MAX_SIZE;
    }

    public boolean isEmpty(){
        return this.count == 0;
    }

    public int getCount() {
        return count;
    }
}
