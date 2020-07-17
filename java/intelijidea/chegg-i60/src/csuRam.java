public class csuRam implements Comparable<csuRam>{
    String name;
    int id;

    // if compareData is true, compare based on name. If compareData is false, compare based on ID.
    static boolean compareData;

    public String toString() {
        return String.format("%-20s%10d", name, id);
    }

    public csuRam(String name, int id) {
        this.name = name;
        this.id = id;
    }

    // Step 2 Part B
    @Override
    public int compareTo(csuRam o) {
        // if compareData if true compare based on name otherwise compare based on id
        if (compareData){
            return this.name.compareTo(o.name);
        }else{
            return Integer.compare(this.id, o.id);
        }
    }

    // Step 3
    @Override
    public boolean equals(Object obj) {
        // student code here
        // check both instance are same or not if same return true otherwise proceed...
        if (this == obj){
            return true;
        }

        // if obj is not instance of csuRam return false otherwise proceed...
        if (!(obj instanceof csuRam)){
            return false;
        }
        if (compareData){
            return this.name.equals(((csuRam) obj).name);
        }else{
            return this.id == ((csuRam) obj).id;
        }
    }

}