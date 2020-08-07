
public class Driver1 {
    public static Sort s = new Sort();
    public static void main(String... args){
        final int SIZE = 10;
        int[] array = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

        System.out.print("Initially, the array is: ");
        displayArray(array, SIZE);
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
            displayArray(arr, arr.length);
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
            displayArray(arr,arr.length);
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

    public static void displayArray(int[] a, int size) {
        int rowSize = 100;
        for (int i = 0; i < size; i++) {
            if (i % rowSize == 0) {
                System.out.println();
            }
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
}
