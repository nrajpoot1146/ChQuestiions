import java.time.LocalTime;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        int[] randArray = new int[1000];
        generate(randArray);

        Scanner sc = new Scanner(System.in);
        int element = sc.nextInt();
        sc.close();

        int t1 = clock();


        insertionSort(randArray);
        System.out.println("Searching start");
        binarySearch(randArray, 0, randArray.length-1, element);


        int t2 = clock();


        System.out.println("Execution time : " + (t2-t1)+"ns");
    }

    public static int clock(){
        return LocalTime.now().getNano();
    }

    public static void generate(int[] array){
        System.out.println("Array generation start");
        for(int i=0; i<1000; i++){
            array[i] = (int) (Math.random()*1000);
        }
    }

    public static void insertionSort(int[] array){
        System.out.println("Array sorting start");
        int n = array.length;
        for (int i = 1; i < n; ++i) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }

    public static int binarySearch(int[] array, int l, int r, int element){

        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (array[mid] == element)
                return mid;

            if (array[mid] > element)
                return binarySearch(array, l, mid - 1, element);
            return binarySearch(array, mid + 1, r, element);
        }

        return -1;
    }
}
