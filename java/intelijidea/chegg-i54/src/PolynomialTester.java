public class PolynomialTester {

    public static void main(String[] args){
        int x = 2; int[] co1 = {5, 0, -3, 8, -4}; int[] co2 = {-2, -4, 0, 5};

        Polynomial p1 = new Polynomial(co1);
        Polynomial p2 = new Polynomial(co2);
        Polynomial p3 = new Polynomial();
        p3.add(p1, p2);
        System.out.println(p1.toString() + " + " + p2.toString() + " = " + p3.toString());
        System.out.println("When x = " + x + " ; " + p3.toString() + " = " + p3.getValue(x));
    }
}
