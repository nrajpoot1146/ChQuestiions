public class Foo {
    public static void divide(int x, int y){
        try {
            System.out.println(y / x);      // throws an ArithmeticException
        }catch (NumberFormatException e){   // throws exception was ArithmeticException
                                            // and catch exception is NumberFormatException so this catch block failed
                                            // to catch ArithmeticException
            System.out.print("A");
        }
        System.out.print("B");
    }

    public static void main(String[] args){
        int x = 0;
        int y = 5;
        try {
            divide(x, y);
        } catch (Exception e) {     // all exception classes extends to Exception class so this block catch
                                    // the ArithmeticException and handle it
            System.out.print("C");  // output is : C
        } catch (ArithmeticException e) {
            System.out.print("D");
        }
    }
}
