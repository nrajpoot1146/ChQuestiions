public class Code2 {
    public static void main(String[] args){
        Trumpet t1 = new Trumpet("Bach", "Professional", 4000.00);
        Trumpet t2 = new Trumpet("Gatzen", "Intermediate", 1900.00);

        System.out.println(t1.toString());
        System.out.println(t2.toString());

        t1.sale(30);
        System.out.println(t1.toString());
        t1.sale(0);
        System.out.println(t1.toString());
    }
}
