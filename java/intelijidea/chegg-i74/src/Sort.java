import java.util.Random;

public class Sort {

    // swap the ith element with the jth elements.
    private void swap(int[] a, int i, int j) {
        int temp;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // initialize the array a with elements from 0 to size-1.
    public void initializeArray(int[] a, int size) {
        for (int i = 0; i < size; i++) a[i] = i;

    }

    // display the elements in the array a, rowSize elements per row.
    public void displayArray(int[] a, int size) {
        int rowSize = 100;
        for (int i = 0; i < size; i++) {
            if (i % rowSize == 0) {
                System.out.println();
            }
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    // randomly swap two elements in a for SWAPTIMES times.
    public void randomizeArray(int[] a, int size) {
        final int SWAPTIMES = 10000;
        Random r = new Random();
        int j, k;
        for (int i = 0; i < SWAPTIMES; i++) {
            j = r.nextInt(size);
            k = r.nextInt(size);
            this.swap(a, j, k);
        }
    }


    // selectionSort
    public void selectionSort(int a[], int size) {
        int i, j, min, minIndex;
        for (j = 0; j < size - 1; j++) {
            minIndex = j;
            min = a[j];
            for (i = j + 1; i < size; i++) {
                if (a[i] < min) {
                    minIndex = i;
                    min = a[i];
                }
            }
            this.swap(a, j, minIndex);
        }
    }

    public static void heapSort(int[] arr) {
        int size = arr.length;
        heapify(arr);
        while (size > 0) {
            int temp = arr[0];
            arr[0] = arr[size - 1];
            arr[size - 1] = temp;
            size--;
            heapi(arr, 0, size - 1);
        }

    }


    private static void heapify(int[] arr) {
        int size = arr.length;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapi(arr, i, size - 1);
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