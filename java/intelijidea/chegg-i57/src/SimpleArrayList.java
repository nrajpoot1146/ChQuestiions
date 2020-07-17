public interface SimpleArrayList<E> {
    /**
     * get number of students in present list
     * @return number of students
     */
    public int size();

    /**
     * add new student object in list
     * @param object of student to be added
     */
    public void add(E object);

    /**
     * get student at given index
     * @param index of student
     * @return student at given index
     */
    public E get(int index);

    /**
     * replace student object
     * @param index of current student
     * @param student new student object
     */
    public void replace(int index, E student);

    /**
     * remove student from present list
     * @param index of student to be remove
     */
    public void remove(int index);

    /**
     * check list is empty or not
     * @return true if list is empty otherwise return false
     */
    public boolean isEmpty();

    /**
     * check list is full or not
     * @return true if list is full otherwise return false
     */
    public boolean isFull();
}
