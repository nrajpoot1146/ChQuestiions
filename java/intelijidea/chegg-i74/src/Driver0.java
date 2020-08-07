import java.util.Random;

public class Driver0 {
    public static Sort s = new Sort();
    public static void main(String... args){
        final int SIZE = 10;
        int[] array = new int[SIZE];

        // initialize integer with random numbers
        Random random = new Random();
        for (int  i=0; i<SIZE; i++){
            array[i] = random.nextInt(100);
        }
        System.out.print("Initially, the array is: ");
        s.displayArray(array, SIZE);
        System.out.println("BUILDING A HEAP");
        heapify(array);
    }

    /**
     * heap sort
     * modified this function to show each step of heap sort
     * @param arr
     */
    public static void heapSort(int[] arr) {
        int size = arr.length;
        heapify(arr);
        System.out.println("Program written by Your Name/012345678," +
                "about to sort the array!");
        System.out.println("HEAP-SORT");
        while (size > 1) {
            System.out.print("heap-sort working on element with array index: "+(size-1));
            int temp = arr[0];
            arr[0] = arr[size - 1];
            arr[size - 1] = temp;
            size--;
            heapi(arr, 0, size - 1);
            s.displayArray(arr, arr.length);
        }

    }


    /**
     * heapify array
     *
     * @param arr
     */
    private static void heapify(int[] arr) {
        int size = arr.length;
        for (int i = size / 2 - 1; i >= 0; i--) {
            System.out.print("max heap on element with array index: "+i);
            heapi(arr, i, size - 1);
            s.displayArray(arr,arr.length);
        }

    }

    private static void heapi(int[] arr, int i, int size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int s = i;
        if (left <= size && arr[left] > arr[i]) {
            s = left;
        }
        if (right <= size && arr[right] > arr[s]) {
            s = right;
        }
        if (i != s) {
            int temp = arr[i];
            arr[i] = arr[s];
            arr[s] = temp;
            heapi(arr, s, size);
        }
    }
}
