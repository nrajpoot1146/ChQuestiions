package assignment03PartA;

public interface PrimaryDataStructureBagInterface<T> {

    public int getCurrentSize();

    public boolean isEmpty();

    public boolean add(T newEntry);

    public boolean removeAllOccurrences(T[][] entries);

    public T[] toArray();
}