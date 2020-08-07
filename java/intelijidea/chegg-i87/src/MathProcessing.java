public interface MathProcessing {
    final public static String SEPARATOR = " ";

    /**
     * return name of operation
     * @return add for adder class, subtract for Subtractor class, multiply for Multiplier class and divide for divider class
     */
    String getKeyword();

    /**
     * return symbol of operation
     * @return + for addition, - for subtraction, * Multiplication, / for division
     */
    char getSymbol();

    /**
     * perform a operation
     * @param leftValue left operand
     * @param rightValue right operand
     * @return result string
     */
    double doCalculation(double leftValue, double rightValue);
}
