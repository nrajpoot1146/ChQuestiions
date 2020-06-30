public class Solution {
    public static void main(String[] args){
        // declaration of double array
        double[] doubleArray = new double[5];
        // initialization of above array
        doubleArray[0] = 2.3;
        doubleArray[1] = 4.7;
        doubleArray[2] = 3.6;
        doubleArray[3] = 6.5;
        doubleArray[4] = 7.8;

        int[] a = {5, 6, 4, 0, 3};

        double[] A = new double[5];
        double mulRes = A[1] + A[A.length - 1]; // where A is array of decimal number
        System.out.println(mulRes); // print multiplication of second element and last element of array

        System.out.println(CheckNonConsecutiveDuplicate(a));
    }

    public static double Area(double radius, double height){
        // calculation of area
        double res = 2 * Math.PI * radius * (radius + height);
        return res;
    }

    public static boolean CheckNonConsecutiveDuplicate(int[] A){
        for (int i=0; i < A.length-1; i++){ // old: for (int i=0; i < A.length-1; i++)
            if (A[i] == A[i+1]) // old: A[i] = A[i+1]
                return false; // old: return true
            // removed code
            // else
            //    return false
        }
        return true; // added code
    }
}
