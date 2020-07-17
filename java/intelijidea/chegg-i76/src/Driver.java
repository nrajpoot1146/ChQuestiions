public class Driver {
    public static void main(String... args){
        Addition addition = new Addition(4, 5);
        Subtraction subtraction = new Subtraction(4, 5);
        Multiplication multiplication = new Multiplication(4, 5);
        Division division = new Division(4, 5);
        Average average = new Average(4, 5);

        // perform different operations
        // print results
        System.out.println("Addition = " + addition.Add());
        System.out.println("Subtraction = " + subtraction.Subtract());
        System.out.println("Multiplication = " + multiplication.Multiply());
        System.out.println("Division = " + division.Divide());
        System.out.println("Average = " + average.Avg());
    }
}
