import java.util.ArrayList;

public class FruitBasket {
    public static void main(String[] args){
        ArrayList<Fruit> arrayList = new ArrayList<Fruit>();

        Fruit[] fruit = new Fruit[6];
        fruit[0] = new Fruit("Apple", "Red");
        fruit[1] = new Fruit("Mango","yellow");
        fruit[2] = new Fruit("Orange", "Orange");
        fruit[3] = new Fruit("Banana", "yellow");
        fruit[4] = new Fruit("Grapes", "Black");
        fruit[5] = new Fruit("Watermelon", "red");

        // adding six fruits in array list
        for (int i=0; i<fruit.length; i++){
            arrayList.add(fruit[i]);
        }

        System.out.println("After adding six fruits in arraylist: ");
        printArrayList(arrayList);
        System.out.println();

        // remove 1st and 3rd fruits
        arrayList.remove(0);
        arrayList.remove(2);

        System.out.println("After removing 1st and 3rd fruits: ");
        printArrayList(arrayList);
        System.out.println();

        // add new fruits at index 3
        arrayList.add(3, new Fruit("Dates", "White"));

        System.out.println("After adding new fruits at index 3: ");
        printArrayList(arrayList);
        System.out.println();

        // change 2nd fruits to green apple
        Fruit fTemp = arrayList.get(1);
        fTemp.setName("Apple");
        fTemp.setColor("Green");

        System.out.println("After changing 2nd fruits to green apple: ");
        printArrayList(arrayList);
        System.out.println();

        // trim the arraylist to hold only 2 fruits
        for (int i = arrayList.size()-1; i>1; i--){
            arrayList.remove(i);
        }
        arrayList.trimToSize();

        System.out.println("After trim to hold 2 fruits:");
        printArrayList(arrayList);

    }

    public static void printArrayList(ArrayList<Fruit> arrayList){
        for (Fruit f : arrayList){
            System.out.println(f.toString());
        }
    }
}
