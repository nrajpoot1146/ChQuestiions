public class ExampleFix {
    void method1() throws ArithmeticException{
        throw new ArithmeticException("error");
    }

    void method2() throws ArithmeticException {
        method1();
    }

    void method3() {
        // old : method2()

        try {
            method2();
        } catch (ArithmeticException arithmeticException){

        }

    }

    public static void main(String[] args){
        ExampleFix obj = new ExampleFix();
        obj.method3();
        System.out.println("End Of Program");
    }
}
