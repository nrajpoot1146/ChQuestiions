
public class P2J10 {

    /**
     * this function calculate matchingDissimilarity
     * used following formula
     * matchingDissimilarity = (n[1][0] + n[0][1]) / length of vector
     * @param v1 first boolean vector
     * @param v2 second boolean vector
     * @return Fraction value
     */
    public static Fraction matchingDissimilarity(boolean[] v1, boolean[] v2){
        int[][] n = getN(v1, v2);
        int num = n[1][0] + n[0][1];
        int denom = v1.length;
        return new Fraction(num, denom);
    }

    /**
     * this function calculate jaccardDissimilarity
     * used following formula
     * jaccardDissimilarity =  (n[1][0] + n[0][1]) / (n[1][1] +  n[1][0] + n[0][1])
     * @param v1 first boolean vector
     * @param v2 second boolean vector
     * @return Fraction value
     */
    public static Fraction jaccardDissimilarity(boolean[] v1, boolean[] v2){
        int[][] n = getN(v1, v2);
        int num = n[1][0] + n[0][1];
        int denom = n[1][1] +  n[1][0] + n[0][1];
        return new Fraction(num, denom);
    }

    /**
     * this function calculate diceDissimilarity
     * used following formula
     * diceDissimilarity = (n[1][0] + n[0][1]) / (2 * n[1][1] +  n[1][0] + n[0][1])
     * @param v1 first boolean vector
     * @param v2 second boolean vector
     * @return Fraction value
     */
    public static Fraction diceDissimilarity(boolean[] v1, boolean[] v2){
        int[][] n = getN(v1, v2);
        int num = n[1][0] + n[0][1];
        int denom = 2 * n[1][1] +  n[1][0] + n[0][1];
        return new Fraction(num, denom);
    }

    /**
     * fucntion calculate rogersTanimonoDissimilarity
     * used following formula
     * rogersTanimonoDissimilarity = (2 * (n[1][0] + n[0][1])) / (n[1][1] +  2 * (n[1][0] + n[0][1]) + n[0][0])
     * @param v1 first boolean vector
     * @param v2 second boolean vector
     * @return Fraction value
     */
    public static Fraction rogersTanimonoDissimilarity(boolean[] v1, boolean[] v2){
        int[][] n = getN(v1, v2);
        int num = 2 * (n[1][0] + n[0][1]);
        int denom = n[1][1] +  2 * (n[1][0] + n[0][1]) + n[0][0];
        return new Fraction(num, denom);
    }

    /**
     * function calculate russellRaoDissimilarity
     * used following formula
     * russellRaoDissimilarity = (n[1][0] + n[0][1] + n[0][0]) / length of vector
     * @param v1 first boolean vector
     * @param v2 second boolean vector
     * @return Fraction value
     */
    public static Fraction russellRaoDissimilarity(boolean[] v1, boolean[] v2){
        int[][] n = getN(v1, v2);
        int num = n[1][0] + n[0][1] + n[0][0];
        int denom = v1.length;
        return new Fraction(num, denom);
    }

    /**
     * function calculate sokalSneathDissimilarity
     * used following formula
     * sokalSneathDissimilarity = 2 * (n[1][0] + n[0][1]) / (n[1][1] +  2 * (n[1][0] + n[0][1]))
     * @param v1 first boolean vector
     * @param v2 second boolean vector
     * @return Fraction value
     */
    public static Fraction sokalSneathDissimilarity(boolean[] v1, boolean[] v2){
        int[][] n = getN(v1, v2);
        int num = 2 * (n[1][0] + n[0][1]);
        int denom = n[1][1] +  2 * (n[1][0] + n[0][1]);
        return new Fraction(num, denom);
    }

    /**
     * fucntion to calculate the value of
     * n00
     * n01
     * n10
     * n11
     * @param v1 first boolean vector
     * @param v2 second boolean vector
     * @return an 2D array of size 4
     */
    private static int[][] getN(boolean[] v1, boolean[] v2){
        int[][] array = new int[2][2];
        array[0][0] = 0;
        array[0][1] = 0;
        array[1][0] = 0;
        array[1][1] = 0;

        for (int i=0; i<v1.length; i++){
            if(v1[i] == false && v2[i] == false){
                array[0][0] += 1;
            }else if(v1[i] == false && v2[i] == true){
                array[0][1] += 1;
            }else if(v1[i] == true && v2[i] == false){
                array[1][0] += 1;
            }else{
                array[1][1] += 1;
            }
        }

        return array;
    }
}
