import java.util.Scanner;

/**
 * class BubbleSortJane
 * works in both mode
 *      mode 1. interactive mode
 *      mode 2. non-interactive mode
 */
public class BubbleSortJane {

    /**
     * main function
     * @param args command line argument
     */
    public static void main(String... args){
        Scanner sc = new Scanner(System.in);
        // check if any argument is present or not
        if (args.length > 0){
            if (args[0].equals("-i")){ // check present argument is equal -i or not
                // if yes read data from user
                System.out.print("Enter length: ");
                int len = sc.nextInt();
                System.out.print("Enter number list: ");
                int[] array = new int[len];
                for (int i=0; i<len; i++){
                    array[i] = sc.nextInt(); // read element of array
                }
                bubbleSort(array); // sort an array
                System.out.print("Sorted number list: ");
                printArray(array); // print array
            }
        } else {
            // for not-interactive mode
            int len = 0;
            if (sc.hasNextInt()) {
                len = sc.nextInt();
            }
            int[] array = new int[len];
            int i = 0;
            while (sc.hasNextInt()) {
                array[i] = sc.nextInt(); // read data from using input redirection
                i++;
            }
            bubbleSort(array); // sort array
            printArray(array); // print array
        }
    }

    /**
     * sort given array
     * use bubble sort algorithm
     * @param array to be sort
     */
    private static void bubbleSort(int[] array){
        for (int i=0; i< array.length-1; i++){
            for (int j=0; j< array.length - i - 1; j++){
                if (array[j] > array[j+1]){
                    swap(array, j, j+1);
                }
            }
        }
    }

    /**
     * swap two number in given array
     * @param array
     * @param i first number
     * @param j second number
     */
    private static void swap(int[] array, int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /**
     * print an array
     * @param array to be print
     */
    private static void printArray(int[] array){
        for (int i=0; i< array.length; i++){
            System.out.print(array[i]+" ");
        }
        System.out.println("$");
    }
}
