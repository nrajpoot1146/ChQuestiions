
public class Polynomial {
    private int[] coefficients;
    private int degree;

    /**
     * an empty constructor
     * sets degree to
     */
    Polynomial(){
        this.degree = 0;
    }

    /**
     * constructor with parameter
     * set coefficient
     * @param coefficients array of coefficients
     */
    Polynomial(int[] coefficients){
        this.coefficients = coefficients;
        this.degree = coefficients.length-1;
    }

    /**
     * get degree of polynomial
     * @return degree of polynomial
     */
    public int getDegree() {
        return degree;
    }

    /**
     * get array of coefficient
     * @return array of coefficient
     */
    public int[] getCoefficients() {
        return coefficients;
    }

    /**
     * generate a string that represent a polynomial
     * @return string
     */
    @Override
    public String toString() {
        StringBuilder poly = new StringBuilder();
        for (int i = 0; i < this.coefficients.length; i++){
            if (coefficients[i] == 0){
                continue;
            }

            if (i == 0){
                poly.append(coefficients[i]);
            }else{
                if (coefficients[i] < 0){
                    poly.append("- ");
                }else{
                    poly.append("+ ");
                }
                poly.append(Math.abs(coefficients[i]));
            }

            if (degree - i == 1){
                poly.append("x ");
            }else if (degree - i != 0)
                poly.append("x "+ (degree-i)+" ");

        }
        return poly.toString();
    }

    /**
     * add two polynomial and store it into current polynomial
     * @param p1 polynomial one
     * @param p2 polynomial two
     */
    public void add(Polynomial p1, Polynomial p2){
        int deg1 = p1.getDegree();
        int deg2 = p2.getDegree();
        this.degree = deg1 > deg2 ? deg1 : deg2;

        int[] coffs = new int[this.degree + 1];

        int[] coffs1 = p1.getCoefficients();
        int[] coffs2 = p2.getCoefficients();

        for (int i = 0; i <= this.degree; i++){
            if (deg1 - i >= 0 && deg2 - i >= 0){
                coffs[this.degree - i] = coffs1[deg1 - i] + coffs2[deg2 - i];
            }else if (deg1 - i >= 0){
                coffs[this.degree - i] = coffs1[deg1 - i];
            }else if (deg2 - i >= 0){
                coffs[this.degree - i] = coffs2[deg2 - i];
            }

        }
        this.coefficients = coffs;
    }

    /**
     * put the value of x and get the result of polynomial
     * @param x value for x
     * @return integer result
     */
    public int getValue(int x){
        int value = 0;
        for (int i = 0; i < coefficients.length; i++){
            value += coefficients[i] * Math.pow(x, degree - i);
        }
        return value;
    }
}
