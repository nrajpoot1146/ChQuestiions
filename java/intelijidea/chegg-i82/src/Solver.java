import java.text.SimpleDateFormat;

public class Solver {
    public static void main(String[] args) {
        final int SIZE = 1000000; // 1 million
        final int Instances = 20;
        int[][] TwoDimArray = new int[Instances][SIZE];

        Sort s = new Sort();

//        removed code:
//        for(int i=0; i    s.initializeArray(TwoDimArray[i], SIZE);
//        s.randomizeArray(TwoDimArray[i], SIZE);
//    }
        for (int i = 0; i < Instances; i++) {
            s.initializeArray(TwoDimArray[i], SIZE);
        }


        final long startTime = System.nanoTime();

//        removed code:
//        final long startTime = System.nanoTime();
//        for(int i=0; i s.insertionSort(TwoDimArray[i], SIZE);
////s.heapSort(TwoDimArray[i], SIZE);
//    }
        for (int i = 0; i < Instances; i++) {
//            s.insertionSort(TwoDimArray[i], SIZE);
            s.heapSort(TwoDimArray[i], SIZE);
        }


        final long duration = (System.nanoTime() - startTime) / 1000000;
        System.out.println("Duration in seconds:" + (duration / 1000.0));

//        for (int i=0;i<SIZE; i++){
//            System.out.print(TwoDimArray[0][i]+" ");
//        }
    }
}