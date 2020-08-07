package ch05.collections;

import java.util.Random;

public class Driver {
    public static void main(String... args){
        SortedArrayCollection<Integer> sc1 = new SortedArrayCollection<>();
        SortedArrayCollection<Integer> sc2 = new SortedArrayCollection<>();

        // fill first SortedArrayCollection
        Random random = new Random();
        for (int i = 0; i<10; i++){
            sc1.add(random.nextInt(100));
        }

        // fill second SortedArrayCollection
        for (int i = 0; i<10; i++){
            sc2.add(random.nextInt(100));
        }

        // print first SortedArrayCollection
        System.out.println("First SortedArrayCollection:\n"+sc1.toString());
        System.out.println();

        // print second SortedArrayCollection
        System.out.println("Second SortedArrayCollection:\n"+sc2.toString());
        System.out.println();

        // combine two SortedArrayCollection
        SortedArrayCollection<Integer> sc3 = sc1.combine(sc2);
        // print combination
        System.out.println("Combination of first and second SortedArrayCollection:\n"+sc3.toString());

        System.out.println();
        int count = sc1.greater(12); // print total number of item in SortedArrayCollection, which is greater tan 12
        System.out.println("Contains "+ count +" items greater than 12 in first SortedArrayCollection");
        // print smallest item
        System.out.println("Smallest item in SortedArrayCollection: "+sc1.smallest());
    }
}
