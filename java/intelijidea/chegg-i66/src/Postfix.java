public class Postfix {

    /**
     * evaluate a postfix expression
     * @param expression to evaluate
     * @return evaluated result
     * @throws StackException if stack is full;
     */
    public static double evaluate(String[] expression) throws StackException {
        Stack<Double> stack = new Stack<Double>();
        for (String s : expression){
            if (s.equals("+")){
                double first = stack.pop();
                double second = stack.pop();
                stack.push(first + second);
            }else if (s.equals("-")){
                double first = stack.pop();
                double second = stack.pop();
                stack.push(second - first);
            }else if (s.equals("/")){
                double first = stack.pop();
                double second = stack.pop();
                stack.push(second / first);
            }else if (s.equals("*")){
                double first = stack.pop();
                double second = stack.pop();
                stack.push(first * second);
            }else{
                stack.push(Double.parseDouble(s));
            }
        }

        return stack.pop();
    }

    public static void main(String[] args) throws StackException {
        String[][] str = {
                {"5", "2", "+"},
                {"1", "2", "-"},
                {"4", "5", "*", "3", "+"},
                {"1", "2", "+", "3", "4", "+", "/"}
        };

        try {
            for (String[] exp : str){
                System.out.println("Answer: " + Postfix.evaluate(exp));
            }
        } catch (StackException stackException){ // catch stack exception
            System.out.println("Error: Stack overflow current stack size: " + stackException.getSize());
        } finally {
            System.out.println("Evaluation Complete.");
        }
    }
}
