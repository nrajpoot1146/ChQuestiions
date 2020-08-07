import java.util.ArrayList;
import java.util.Scanner;

public class LoShuMagicSquare {

    /**
     * fill magic square arrayList
     * @param magicSquare array List to be filled
     */
    static void fillMagicSquare(ArrayList<ArrayList<Integer>> magicSquare) {

        int i = magicSquare.size() / 2;
        int j = magicSquare.size() - 1;

        for (int number=1; number<=magicSquare.size() * magicSquare.size();) {
            if (i == -1 && j == magicSquare.size()) {
                j = magicSquare.size() - 2; i = 0;
            } else {
                j = (j == magicSquare.size()) ? 0 : j; // if column exceed the column size
                i = (i < 0) ? (magicSquare.size() - 1) : i; // if row is negative set row to arraySize - 1
            }

            if (magicSquare.get(i).get(j) != 0) { // if current position is already filled
                j -= 2; i++;
            } else {
                magicSquare.get(i).set(j, number);
                j++; i--; number++;
            }
        }
    }

    /**
     * print magic square method
     * @param magicSquare arraylist of magic square
     */
    static void printMagicSquare(ArrayList<ArrayList<Integer>> magicSquare){
        for (int i=0; i<magicSquare.size(); i++){
            for (int j=0; j<magicSquare.size(); j++){
                System.out.print(magicSquare.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    public static void main(String... args){
        ArrayList<ArrayList<Integer>> magicSquare = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        System.out.printf("Enter size of array: ");
        int n = sc.nextInt();

        if (n % 2 == 0){
            System.out.println("please enter an odd number: ");
            return;
        }

        // fill each element of array by 0
        for (int i=0; i<n; i++){
            magicSquare.add(new ArrayList<>());
            for (int j=0; j<n; j++){
                magicSquare.get(i).add(0);
            }
        }

        // fill magic square
        fillMagicSquare(magicSquare);

        // print magic square
        printMagicSquare(magicSquare);
    }
}
