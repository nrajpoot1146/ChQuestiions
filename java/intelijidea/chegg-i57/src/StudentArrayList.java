import java.util.Arrays;
import java.util.NoSuchElementException;

public class StudentArrayList<E> implements SimpleArrayList<E>{
    private int size;
    private E[] studentList;

    StudentArrayList(){
        this.size = 0;
        this.studentList = (E[]) new Object[10];
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public void add(E object) {
        if (isFull()){
            this.grow();
        }
        this.studentList[this.size] = object;
        this.size++;
    }

    @Override
    public E get(int index) {
        if (isEmpty() || index > this.size - 1){
            throw new NoSuchElementException();
        }
        return this.studentList[index];
    }

    @Override
    public void replace(int index, E student) {
        if (isEmpty() || index > this.size - 1){
            throw new NoSuchElementException();
        }
        this.studentList[index] = student;
    }

    @Override
    public void remove(int index) {
        if (isEmpty() || index > this.size - 1){
            throw new NoSuchElementException();
        }

        if (index == this.size-1){
            this.size--;
            return;
        }

        for (int i = index; i < this.size - 1; i++){
            this.studentList[i] = this.studentList[i+1];
        }

        this.size--;
    }

    @Override
    public boolean isEmpty() {
        return this.size == 0;
    }

    @Override
    public boolean isFull() {
        return this.size == this.studentList.length;
    }

    private void grow(){
        E[] newList  = (E[]) new Object[this.studentList.length+2];
        for (int i = 0; i < this.studentList.length; i++){
            newList[i] = studentList[i];
        }
        this.studentList = newList;
    }

    @Override
    public String toString() {
        String res = "[";

        for (int i = 0; i < this.size; i++){
            res += this.studentList[i];

            if (i < this.size - 1){
                res += ", ";
            }
        }

        return res + "]";
    }
}
