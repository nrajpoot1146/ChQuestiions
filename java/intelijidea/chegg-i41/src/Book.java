public class Book {
    private String title;
    private String author;
    private String yearOfPublication;

    /**
     *
     * @param title of books
     */
    Book(String title){
        this.title = title;
        this.author = null;
        this.yearOfPublication = null;
    }

    /**
     *
     * @param title of book
     * @param author author of book
     * @param yearOfPublication year of publication of book
     */
    Book(String title, String author, String yearOfPublication){
        this.title = title;
        this.author = author;
        this.yearOfPublication = yearOfPublication;
    }

    /**
     * setter method for title of book
     * @param title of book
     */
    public void setTitle(String title) {
        this.title = title;
    }

    /**
     * getter method of title of book
     * @return title of book
     */
    public String getTitle() {
        return title;
    }

    /**
     * setter method for book of author
     * @param author of book
     */
    public void setAuthor(String author) {
        this.author = author;
    }

    /**
     * getter method for author of book
     * @return author of book
     */
    public String getAuthor() {
        return author;
    }

    /**
     * setter method for year of publication of book
     * @param yearOfPublication year of publication of book
     */
    public void setYearOfPublication(String yearOfPublication) {
        this.yearOfPublication = yearOfPublication;
    }

    /**
     * getter method for year of publication of book
     * @return year of publication of book
     */
    public String getYearOfPublication() {
        return yearOfPublication;
    }

    @Override
    public String toString() {
        return "title='" + title + '\'' +
                ", author='" + author + '\'' +
                ", yearOfPublication='" + yearOfPublication + '\'';
    }
}
