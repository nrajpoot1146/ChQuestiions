import java.util.ArrayList;

public class Demo {
    public static void main(String[] args){
        ArrayList<String> arrayListObject = new ArrayList<>();

        arrayListObject.add("A");
        arrayListObject.add("B");
        arrayListObject.add("C");

        System.out.println(arrayListObject);

        // old : ArrayList<String> arrayListClone = (ArrayList<String>) arrayListObject.clone();
        ArrayList<String> arrayListClone = (ArrayList<String>) arrayListObject.clone();
        System.out.println(arrayListClone);
    }
}
