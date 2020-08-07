import java.util.Random;

class Sort {

    // swap the ith element with the jth elements.
    private void swap(int[] a, int i, int j) {
        int temp;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // initialize the array a with elements from 0 to size-1.
//    removed code:
//    public void initializeArray(int[] a, int size){
//        for (int i=0;i
//    }
    public void initializeArray(int[] a, int size) {
        for (int i = 0; i < size; i++)
            a[i] = i;
    }

//    removed code:
//    public void insertionSort(int a[],int n)
//    {
//        for(int i=1;i                int j=i-1,val=a[i];
//        while(j>=0&&a[j]                a[j+1]=a[j];
//        j--;}
//    a[++j]=val;
//}
//       }
    public void insertionSort(int a[], int n) {
        for (int i=0; i < n; i++){
            int temp = a[i];
            int k = i-1;
            while (k >= 0 && a[k] > temp){
                a[k+1] = a[k];
                k--;
            }
            a[k+1] = temp;
        }
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


    public void heapSort(int[] arr, int size) {
        heapify(arr);
        while (size > 0) {
            int temp = arr[0];
            arr[0] = arr[size - 1];
            arr[size - 1] = temp;
            size--;
            heapi(arr, 0, size - 1);
        }

    }


    private void heapify(int[] arr) {
        int size = arr.length;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapi(arr, i, size - 1);
        }

    }

    private void heapi(int[] arr, int i, int size) {
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