import java.util.Random;

public class Solution {
    public static void main(String... args){
        int[] array = new int[1000];
        filledArray(array);
        System.out.println("unsorted array: ");
        print(array);

        // sort array
        sort(array);
        System.out.println("Sorted array: ");
        sort(array); // print sort array
        print(array);

        int[] freq = getFrequency(array); // get frequency array
        // print frequency of each number
        System.out.println("Frequency of each number: ");
        System.out.println("number : frequency");
        for (int i=1; i<=10; i++){
            System.out.println(i + " : " + freq[i]);
        }

        System.out.println("Sum = "+sum(array)); // print sum of array elements
        System.out.println("Average = "+ average(array)); // print average of array elements
    }

    /**
     * fill an array with random number between 1 to 10
     * @param array to be fiil
     */
    public static void filledArray(int[] array){
        Random random = new Random();

        for (int i=0; i<array.length; i++){
            // fill array elements in range 1 to 10
            array[i] = random.nextInt(10) + 1;
        }
    }

    /**
     * sort an array
     * use bubble sort algorithm
     * @param array to be sort
     */
    public static void sort(int[] array){
        for (int i=0; i<array.length - 1; i++){
            for (int j=0; j<array.length-i-1; j++) {
                if (array[j] > array[j+1]){
                    // swap an element
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }

    /**
     * get frequency of each number
     * @param array for input
     * @return frequency array
     */
    public static int[] getFrequency(int[] array){
        int[] freq = new int[11];
        for (int i=0; i<freq.length; i++){
            freq[i] = 0;
        }

        for (int i=0; i<array.length; i++){
            freq[array[i]]++;
        }
        return freq;
    }

    /**
     * calculate average of elements of an array
     * @param array
     * @return return average
     */
    public static double average(int[] array){
        int sum = sum(array);
        double average = ((double) sum) / array.length;
        return average;
    }

    /**
     * calculate sum of elements of array
     * @param array
     * @return sum
     */
    public static int sum(int[] array){
        int sum = 0;
        for (int i=0; i<array.length; i++){
            sum += array[i];
        }
        return sum;
    }

    /**
     * print elements of an array
     * @param array input array
     */
    public static void print(int[] array){
        for (int i=0; i<array.length; i++){
            System.out.print(array[i]);
            if (i != array.length-1){
                System.out.print(", ");
            }
        }
        System.out.println();
    }
}
