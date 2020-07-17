import java.util.Arrays;

/**
 * class Sample Array has used only for testing purpose of new sort function
 * there is no need to include with your code
 */
public class SampleDriver {
    public static void main(String... args){
        Integer[] a = {100, 11, 2, 46, 3, 2, 9, 89, 33, 46}; // declare and initialize an integer array
        System.out.println("Array before sorting: "+Arrays.toString(a)); // print array before sorting
        Sorting.sort(a); // sort array using newly defined function
        System.out.println("Array after sorting: "+Arrays.toString(a)); // print array after sorting
    }
}
