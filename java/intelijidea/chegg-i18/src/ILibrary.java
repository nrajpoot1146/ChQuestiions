import java.util.List;

public interface ILibrary {

    /**
     * Adds an item to the library. If the call number within the item does
     * not exist in the library, the copy number within the item will be
     * set to 1 by this method. If copies of the item already exist in
     * the library, the copy number will be set to the next copy number. For
     * example, if the highest copy number is 3, the item added will be copy
     * number 4.
     *
     * @param item the item to be added to library.
     */
    void addItem(Item item);

    /**
     * Retrieves all items in the library. This will be used by tests to
     * check that the contents have been updated correctly.
     *
     * @return the items
     */
    List<Item> getItems();

    /**
     * Deletes a item from the library.
     *
     * @param callNumber the call number of the item to be deleted.
     * @param copy       the copy number of the item to be deleted.
     * @return <code>true</code> if the item was deleted successfully,
     * and <code> false</code> if the item was not deleted.
     */
    boolean deleteItem(String callNumber, int copy);

    /**
     * Checks out an item from the library. The borrower id is stored in the item.
     *
     * @param callNumber the call number of the item to be checked out
     * @param copy       the copy of the item to be checked out
     * @param borrower   the id of the person borrowing the item
     * @return <code>true</code> if the item was checked out successfully,
     * and <code> false</code> if it was not.
     */
    boolean checkOut(String callNumber, int copy, String borrower);

    /**
     * Checks an item back into the library. The borrower id is
     * set to <code> null </code> in the item.
     *
     * @param callNumber the call number of the item to be checked in
     * @param copy       the copy of the item to be checked in
     * @return <code>true</code> if the item was checked in successfully,
     * and <code> false</code> if it was not.
     */
    boolean checkIn(String callNumber, int copy);

    /**
     * Creates and returns a list of media items that match the call number.
     *
     * @param callNumber the call number of the media items
     * @return a list of matching media items.
     */
    List<Item> findItems(String callNumber);
}