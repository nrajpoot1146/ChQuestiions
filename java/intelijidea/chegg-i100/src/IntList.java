import java.util.ArrayList;

public class IntList extends IntContainer{
    private ArrayList<Integer> arrayList;

    IntList(){
        super();
        this.arrayList = new ArrayList<>();
    }
    @Override
    public int compareTo(IntContainer o) {
        if (arrayList.size() > o.size){
            return 1;
        }

        if (arrayList.size() < o.size){
            return -1;
        }

        boolean flag = false;
        Integer sumA = 0;
        Integer sumB = 0;
        for (int i=0; i<arrayList.size(); i++){
            sumA += arrayList.get(i);
            sumB += o.get(i);
            if (arrayList.get(i) != o.get(i)) {
                flag = true;
            }
        }

        return sumA.compareTo(sumB);
    }

    @Override
    void set(int x, int pos) {
        if (pos < this.size){
            this.arrayList.set(pos, x);
        }
    }

    @Override
    int get(int pos) {
        if (pos < this.size){
            return this.arrayList.get(pos);
        }
        return -1;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i=0; i < this.size; i++){
            stringBuilder.append(this.arrayList.get(i));
            stringBuilder.append(" ");
        }
        return stringBuilder.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this.size != ((IntContainer) obj).size){
            return false;
        }

        for (int i=0; i<this.size; i++){
            if (this.get(i) != ((IntContainer) obj).get(i)){
                return false;
            }
        }
        return true;
    }

    @Override
    public void rand() {
        for (int i=0; i<this.MaxCapacity; i++){
            int num = random.nextInt(100)+ 1;
            size++;
            this.arrayList.add(num);
        }
    }
}
